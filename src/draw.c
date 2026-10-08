/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:44:46 by achanel           #+#    #+#             */
/*   Updated: 2022/04/05 10:32:53 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_helper(t_all *all, t_ray *ray, t_point draw_p)
{
	unsigned int	color;
	t_point			tex_p;

	while (ray->draw_start <= ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos;
		if (ray->tex_y < 0)
			ray->tex_y = 0;
		else if (ray->tex_y >= all->txt[ray->tex].h)
			ray->tex_y = all->txt[ray->tex].h - 1;
		ray->tex_pos += ray->tex_stepy;
		tex_p.x = ray->tex_x;
		tex_p.y = ray->tex_y;
		color = get_texture_color(all->txt[ray->tex], tex_p);
		draw_p.x = ray->pix_x;
		draw_p.y = ray->draw_start;
		my_mlx_pixel_put(all->display, draw_p, color);
		ray->draw_start++;
	}
}

void	draw_line(t_all *all, t_ray *ray, int x)
{
	unsigned int	color;
	int				i;
	t_point			draw_p;

	draw_p.x = x;
	i = 0;
	while (i < ray->draw_start)
	{
		draw_p.y = i;
		color = all->ceilling;
		my_mlx_pixel_put(all->display, draw_p, color);
		i++;
	}
	draw_helper(all, ray, draw_p);
	while (ray->draw_start < HEIGHT)
	{
		color = all->floor;
		draw_p.x = ray->pix_x;
		draw_p.y = ray->draw_start;
		my_mlx_pixel_put(all->display, draw_p, color);
		ray->draw_start++;
	}
}

void	draw_door(t_all *all, t_ray *ray)
{
	t_door			*door;
	t_point			tex_p;
	t_point			draw_p;
	unsigned int	color;
	int				shift;
	int				len;
	int				t;
	int				y;

	door = find_door(all, ray->mapx, ray->mapy);
	len = ray->draw_end - ray->draw_start;
	if (len <= 0)
		return ;
	shift = 0;
	if (door)
		shift = (int)(door->offset * ray->line_height);
	draw_p.x = ray->pix_x;
	tex_p.x = ray->tex_x;
	y = ray->draw_start - 1;
	while (++y <= ray->draw_end)
	{
		t = (y - ray->draw_start) + shift;
		if (t < 0 || t >= len)
			continue ;
		draw_p.y = y;
		if (!all->txt[DOOR_TEX].addr || all->txt[DOOR_TEX].h <= 0)
		{
			my_mlx_pixel_put(all->display, draw_p, 0x00664C33);
			continue ;
		}
		tex_p.y = (int)((float)t * all->txt[DOOR_TEX].h / (float)len);
		color = get_texture_color(all->txt[DOOR_TEX], tex_p);
		my_mlx_pixel_put(all->display, draw_p, color);
	}
}

void	draw_crosshair(t_all *all)
{
	t_point	p;
	int		i;

	i = -10;
	while (++i <= 10)
	{
		p.x = WIDTH / 2 + i;
		p.y = HEIGHT / 2;
		my_mlx_pixel_put(all->display, p, 0x00FFFFFF);
		p.x = WIDTH / 2;
		p.y = HEIGHT / 2 + i;
		my_mlx_pixel_put(all->display, p, 0x00FFFFFF);
	}
}
