#include "cub3D.h"

static int	get_color(t_all *all, t_ray *ray)
{
	if (ray->side == 1)
	{
		if ((ray->stepx == -1 && ray->stepy == -1) ||
			(ray->stepx == 1 && ray->stepy == -1))
			return (all->color_east);
		if ((ray->stepx == -1 && ray->stepy == 1) ||
			(ray->stepx == 1 && ray->stepy == 1))
			return (all->color_west);
	}
	if ((ray->stepx == -1 && ray->stepy == -1) ||
		(ray->stepx == -1 && ray->stepy == 1))
		return (all->color_north);
	return (all->color_south);
}

static int	smog(double d, int color)
{
	int	r;
	int	g;
	int	b;

	r = color / 256 / 256;
	g = color / 256 % 256;
	b = color % 256;
	if (r > 0)
		r = r - ((r * d) / 4);
	if (g > 0)
		g = g - ((g * d) / 4);
	if (b > 0)
		b = b - ((b * d) / 4);
	r = r <= 0 || r > 255 ? 0 : r;
	g = g <= 0 || g > 255 ? 0 : g;
	b = b <= 0 || b > 255 ? 0 : b;
	color = (r * 256 * 256) + (g * 256) + b;
	return (color);
}

void		draw_line(t_all *all, t_ray *ray, int x)
{
	int		i;
	double	init;
	double	d;
    t_point p;

    p.x = x;
	p.y = -1;
	init = (HEIGHT - 1) / 9;
	while (++p.y < ray->draw_start)
	{
		d = (double)p.y / init;
		d = d < 0 ? d * -1 : d;
        my_mlx_pixel_put(all, p, 0x065a69);
	}
	p.y--;
	while (++p.y <= ray->draw_end && p.y < HEIGHT)
        my_mlx_pixel_put(all, p, smog(ray->walldist, get_color(all, ray)));
	p.y--;
	while (++p.y < HEIGHT)
	{
		d = 9 - (double)p.y / init;
		d = d < 0 ? d * -1 : d;
		my_mlx_pixel_put(all, p, 0x340707);
	}
}