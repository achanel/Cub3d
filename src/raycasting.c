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
		ray->sidedx = (float)(plr.x - 1 - ray->mapx) * (ray->ddistx * -1);
	}
	if (ray->diry < 0)
	{
		ray->stepy = -1;
		ray->sidedy = (float)(plr.y - ray->mapy) * ray->ddisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedy = (float)(plr.y - 1 - ray->mapy) * (ray->ddisty * -1);
	}
}

static void	hit_wall(t_all *all, t_ray *ray)
{
	while (ray->hit == 1)
	{
		if (ray->sidedy < ray->sidedx)
		{
			ray->sidedy += ray->ddisty;
			ray->mapy += ray->stepy;
			ray->side = 0;//NO_SO
		}
		else
		{
			ray->sidedx += ray->ddistx;
			ray->mapx += ray->stepx;
			ray->side = 1;//WE_EA
		}
		if (ray->side)
			ray->walldist = ray->sidedx - ray->ddistx;
		else
			ray->walldist = ray->sidedy - ray->ddisty;
	}
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
	if (ray->side == 0)
		ray->wall_x = all->plr.x + ray->walldist * ray->dirx;
	else
		ray->wall_x = all->plr.y + ray->walldist * (ray->diry * -1);
	ray->wall_x -= floor(ray->wall_x);
	if (ray->side == 0 && ray->stepy == -1)
		ray->tex = 3;
	else if (ray->side == 0)
		ray->tex = 2;
	else if (ray->side == 1 && ray->stepx == 1)
		ray->tex = 1;
	else
		ray->tex = 0;
	ray->tex_x = (int)(ray->wall_x * (float)all->txt[ray->tex].w);
	ray->tex_stepy = (float)all->txt[ray->tex].h / ray->line_height;
	ray->tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * ray->tex_stepy;
}

void	ray_init(t_ray *ray, t_plr plr, int x)
{
	ray->camerax = (float)(2 * x) / WIDTH - 1;
	ray->ray_r = plr.angle;
	ray->plane_x = 0.66 * sin(ray->ray_r);
	ray->plane_y = -0.66 * cos(ray->ray_r);
	ray->hit = 0;
	ray->dirx = cos(ray->ray_r) + ray->plane_x * ray->camerax;
	ray->diry = sin(ray->ray_r) + ray->plane_y * ray->camerax;
	ray->mapx = (int)ray->posx;
	ray->mapy = (int)ray->posy;
	ray->ddistx = fabsf(1 /ray->dirx);
	ray->ddisty = fabsf(1 /ray->diry);
}

void    ft_raycasting(t_all *all)
{
	t_ray	ray;

	ray.pix_x = 1;
	while (ray.pix_x < WIDTH)
	{
		ray_init(&ray, all->plr, ray.pix_x);
		cal_side_dist(&ray, all->plr);
		hit_wall(all, &ray);
		cal_draw_start_end(&ray, all);
		draw_line(all, &ray, ray.pix_x);//
		ray.pix_x++;
	}
}