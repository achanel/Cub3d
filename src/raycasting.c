/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:49:31 by achanel           #+#    #+#             */
/*   Updated: 2022/04/06 12:00:00 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	cal_side_dist(t_ray *ray, t_plr plr)
{
	if (ray->dirx < 0)
	{
		ray->stepx = -1;
		ray->sidedx = (float)(plr.x - ray->mapx) * ray->ddistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedx = (float)(ray->mapx + 1 - plr.x) * ray->ddistx;
	}
	if (ray->diry > 0)
	{
		ray->stepy = -1;
		ray->sidedy = (float)(plr.y - ray->mapy) * ray->ddisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedy = (float)(ray->mapy + 1 - plr.y) * ray->ddisty;
	}
}

static int	out_of_map(t_all *all, t_ray *ray)
{
	if (ray->mapy < 0 || ray->mapy >= all->map_h || !all->map[ray->mapy]
		|| ray->mapx < 0)
		return (1);
	if (ray->mapx >= (int)ft_strlen(all->map[ray->mapy]))
		return (1);
	return (0);
}

static int	tile_open(t_all *all, t_ray *ray)
{
	t_door	*door;

	if (all->map[ray->mapy][ray->mapx] == 'D')
	{
		door = find_door(all, ray->mapx, ray->mapy);
		if (!door || door->offset >= 1.0f)
			return (1);
	}
	return (0);
}

static void	hit_wall(t_all *all, t_ray *ray, int stop_at_doors)
{
	while (ray->hit == 0)
	{
		if (ray->sidedy < ray->sidedx)
		{
			ray->sidedy += ray->ddisty;
			ray->mapy += ray->stepy;
			ray->side = NS;
		}
		else
		{
			ray->sidedx += ray->ddistx;
			ray->mapx += ray->stepx;
			ray->side = WE;
		}
		if (out_of_map(all, ray))
		{
			ray->hit = 1;
			break ;
		}
		if (all->map[ray->mapy][ray->mapx] == '1')
			ray->hit = 1;
		else if (all->map[ray->mapy][ray->mapx] == 'D' && !tile_open(all, ray))
		{
			if (stop_at_doors)
			{
				ray->is_door = 1;
				ray->hit = 1;
			}
		}
	}
	if (ray->side == 0)
		ray->walldist = ray->sidedx - ray->ddistx;
	else
		ray->walldist = ray->sidedy - ray->ddisty;
}

static void	cal_draw_start_end(t_ray *ray, t_all *all)
{
	ray->line_height = (int)(HEIGHT / ray->walldist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
	if (ray->side == NS)
		ray->wall_x = all->plr.x + ray->walldist * ray->dirx;
	else
		ray->wall_x = all->plr.y + ray->walldist * (ray->diry * -1);
	ray->wall_x -= floor(ray->wall_x);
	if (ray->is_door)
		ray->tex = DOOR_TEX;
	else if (ray->side == NS && ray->stepy == -1)
		ray->tex = SOUTH;
	else if (ray->side == NS)
		ray->tex = NORTH;
	else if (ray->side == WE && ray->stepx == 1)
		ray->tex = WEST;
	else
		ray->tex = EAST;
	ray->tex_x = (int)(ray->wall_x * (float)all->txt[ray->tex].w);
	if (ray->tex_x >= all->txt[ray->tex].w)
		ray->tex_x = all->txt[ray->tex].w - 1;
	ray->tex_stepy = (float)all->txt[ray->tex].h / ray->line_height;
	ray->tex_pos = (ray->draw_start - HEIGHT / 2
			+ ray->line_height / 2) * ray->tex_stepy;
}

static void	ray_init(t_ray *ray, t_plr plr, int x)
{
	ray->camerax = (float)(2 * x) / WIDTH - 1;
	ray->ray_r = plr.angle;
	ray->plane_x = 0.66 * sin(ray->ray_r);
	ray->plane_y = -0.66 * cos(ray->ray_r);
	ray->hit = 0;
	ray->is_door = 0;
	ray->dirx = cos(ray->ray_r) + ray->plane_x * ray->camerax;
	ray->diry = sin(ray->ray_r) + ray->plane_y * ray->camerax;
	ray->mapx = (int)plr.x;
	ray->mapy = (int)plr.y;
	ray->ddistx = fabsf(1 / ray->dirx);
	ray->ddisty = fabsf(1 / ray->diry);
}

static void	cast_and_draw(t_all *all, t_ray *ray, int x)
{
	t_ray	bg;

	ray_init(ray, all->plr, x);
	cal_side_dist(ray, all->plr);
	hit_wall(all, ray, 1);
	cal_draw_start_end(ray, all);
	all->z_buffer[x] = ray->walldist;
	if (ray->is_door)
	{
		ray_init(&bg, all->plr, x);
		bg.pix_x = x;
		cal_side_dist(&bg, all->plr);
		hit_wall(all, &bg, 0);
		cal_draw_start_end(&bg, all);
		draw_line(all, &bg, x);
		draw_door(all, ray);
	}
	else
		draw_line(all, ray, x);
}

void	ft_raycasting(t_all *all)
{
	t_ray	ray;

	ray.pix_x = 0;
	while (ray.pix_x < WIDTH)
	{
		cast_and_draw(all, &ray, ray.pix_x);
		ray.pix_x++;
	}
	draw_sprites(all);
	if (all->crosshair)
		draw_crosshair(all);
	if (all->mini_flag)
		draw_mini_map(all);
}
