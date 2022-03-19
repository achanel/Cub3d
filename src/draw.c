#include "cub3D.h"

<<<<<<< HEAD
=======
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

// static int	smog(double d, int color)
// {
// 	int	r;
// 	int	g;
// 	int	b;

// 	r = color / 256 / 256;
// 	g = color / 256 % 256;
// 	b = color % 256;
// 	if (r > 0)
// 		r = r - ((r * d) / 4);
// 	if (g > 0)
// 		g = g - ((g * d) / 4);
// 	if (b > 0)
// 		b = b - ((b * d) / 4);
// 	r = r <= 0 || r > 255 ? 0 : r;
// 	g = g <= 0 || g > 255 ? 0 : g;
// 	b = b <= 0 || b > 255 ? 0 : b;
// 	color = (r * 256 * 256) + (g * 256) + b;
// 	return (color);
// }

>>>>>>> 5a7d78122034e1fa7b31cc18bd870bd12670d18f
void		draw_line(t_all *all, t_ray *ray, int x)
{
	unsigned int	color;
	int				i;
	t_point			draw_p;
	t_point			tex_p;

	draw_p.x = x;
	i = 0;
	while (i < ray->draw_start)
	{
<<<<<<< HEAD
		draw_p.y = i;
		color = 0x00FFFF;
		my_mlx_pixel_put(all->win, draw_p, color);
		i++;
	}
	while (ray->draw_start < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos;
		ray->tex_pos += ray->tex_stepy;
		tex_p.x = ray->tex_x;
		tex_p.y = ray->tex_y;
		color = get_texture_color(all->txt[ray->tex], tex_p);
		draw_p.x = ray->pix_x;
		draw_p.y = ray->draw_start;
		my_mlx_pixel_put(all->win, draw_p, color);
		ray->draw_start++;
=======
		d = (double)p.y / init;
		d = d < 0 ? d * -1 : d;
        my_mlx_pixel_put(all, p, all->colorsky);
	}
	p.y--;
	while (++p.y <= ray->draw_end && p.y < HEIGHT)
        my_mlx_pixel_put(all, p, get_color(all, ray));
	p.y--;
	while (++p.y < HEIGHT)
	{
		d = 9 - (double)p.y / init;
		d = d < 0 ? d * -1 : d;
		my_mlx_pixel_put(all, p, all->colorground);
>>>>>>> 5a7d78122034e1fa7b31cc18bd870bd12670d18f
	}
	while (ray->draw_start < HEIGHT)
	{
		color = 0x340707;
		draw_p.x = ray->pix_x;
		draw_p.y = ray->draw_start;
		my_mlx_pixel_put(all->win, draw_p, color);
		ray->draw_start++;
	}
}
