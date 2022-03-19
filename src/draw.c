#include "cub3D.h"

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
