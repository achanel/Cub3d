#include "cub3D.h"

void	mini_map_pixel_put(t_img img, t_point point, int color)
{
	char	*dst;

	if (point.x >= (WIDTH - MINI_MAP) && point.y < MINI_MAP / 2)
	{
		dst = img.addr + (point.y * img.line_length
				+ point.x * (img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
	else
		return ;
}

void	ft_scale_img(t_point point, t_all *all, int	color, int scale)
{
	t_point	end;

	point.x += (800);
	end.x = (point.x + 1) * scale;
	end.y = (point.y + 1) * scale;
	point.x *= scale;
	point.y *= scale;
	while (point.y < end.y)
	{
		while (point.x < end.x)
		{
			mini_map_pixel_put(all->display, point, color);
			point.x++;
		}
		point.x -= scale;
		point.y++;
	}
}

void	draw_map_helper(t_all *all)
{
	t_point	i;
	
	i.y = 0;
	while (all->map[i.y])
	{
		i.x = 0;
		while (all->map[i.y][i.x])
		{
			if (all->map[i.y][i.x] == 'N')
				ft_scale_img(i, all, 0xFF0000, 4);
			i.x++;
		}
		i.y++;
	}
}

void	draw_mini_map(t_all *all)
{
	t_point	i;
	
	i.y = 0;
	while (all->map[i.y])
	{
		i.x = 0;
		while (all->map[i.y][i.x])
		{
			if (all->map[i.y][i.x] == '1')
				ft_scale_img(i, all, 0xFFFFFF, 8);
			else
				ft_scale_img(i, all, 0x000000, 8);
			i.x++;
		}
		i.y++;
	}
	// draw_map_helper(all);
}