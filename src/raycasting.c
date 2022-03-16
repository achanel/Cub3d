#include "cub3D.h"

// void		draw_player_dir(t_all *all)
// {
// 	double rayx;
// 	double rayy;

// 	rayx = all->plr->x + all->plr->dir_x;
// 	rayy = all->plr->y + all->plr->dir_y;
// 	draw_ray(all, rayx, rayy, 0x00ff00);
// }

static void	cal_side_dist(t_ray *ray)
{
	if (ray->dirx < 0)
	{
		ray->stepx = -1;
		ray->sidedx = (ray->posx - ray->mapx) * ray->ddistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedx = (ray->mapx + 1.0 - ray->posx) * ray->ddistx;
	}
	if (ray->diry < 0)
	{
		ray->stepy = -1;
		ray->sidedy = (ray->posy - ray->mapy) * ray->ddisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedy = (ray->mapy + 1.0 - ray->posy) * ray->ddisty;
	}
}

static void	hit_wall(t_all *all, t_ray *ray)
{
	while (1)
	{
		if (ray->sidedx < ray->sidedy)
		{
			ray->sidedx += ray->ddistx;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedy += ray->ddisty;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (all->map[ray->mapy][ray->mapx] > 0)
			break ;
	}
}

static void	cal_dist_ray_to_perpwall(t_ray *ray)
{
	if (ray->side == 0)
	{
		ray->walldist = (ray->mapx - ray->posx + (1 - ray->stepx) / 2)
		/ ray->dirx;
	}
	else
	{
		ray->walldist = (ray->mapy - ray->posy + (1 - ray->stepy) / 2)
		/ ray->diry;
	}
}

static void	cal_draw_start_end(t_ray *ray)
{
	int line_height;

	line_height = (int)(HEIGHT / ray->walldist);
	ray->draw_start = -line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}

void    ft_raycasting(t_all *all)
{
    int		x;
	t_ray	ray;

	// draw_map(all);
	ray.posx = all->plr->x;
	ray.posy = all->plr->y;
	x = -1;
	while (++x < WIDTH)
	{
		ray.camerax = (2 * x) / (double)WIDTH - 1;
		ray.dirx = all->plr->dir_x + all->plr->plane_x * ray.camerax;
		ray.diry = all->plr->dir_y + all->plr->plane_y * ray.camerax;
		ray.mapx = (int)ray.posx;
		ray.mapy = (int)ray.posy;
		ray.ddistx = sqrt(1 + pow(ray.diry, 2) / pow(ray.dirx, 2));
		ray.ddisty = sqrt(1 + pow(ray.dirx, 2) / pow(ray.diry, 2));
		cal_side_dist(&ray);
		hit_wall(all, &ray);
		cal_dist_ray_to_perpwall(&ray);
		cal_draw_start_end(&ray);
		draw_line(all, &ray, x);
	}
	// draw_player_dir(all);
}