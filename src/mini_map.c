/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:53:44 by achanel           #+#    #+#             */
/*   Updated: 2022/03/30 18:14:58 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_lov(t_point plr, t_all *all, int scale)
{
	float	bx;
	float	by;
	float	d;
	float	pente;
	t_point	lov;

	bx = cos(all->plr.angle);
	by = sin(all->plr.angle);
	d = 0;
	if (bx < 0.05 && bx > -0.05)
		bx = 0.05;
	pente = by / bx;
	while (sqrtf(((d * pente) * (d * pente)) + d * d) <= scale * 3)
	{
		lov.y = plr.y * scale + -d * pente + 2;
		lov.x = plr.x * scale + d + 2;
		my_mlx_pixel_put(all->display, lov, 0x00FF00);
		if (bx < 0)
			d -= .1;
		else
			d += .1;
	}
}

static void	ft_scale_img(t_point point, t_all *all, int color, int scale)
{
	char	*dst;

	all->mini.x = point.x * scale;
	all->mini.y = point.y * scale;
	all->mini.y_end = (point.y + 1) * scale;
	all->mini.x_end = (point.x + 1) * scale;
	while (all->mini.y < all->mini.y_end)
	{
		while (all->mini.x < all->mini.x_end)
		{
			dst = all->display.addr + (all->mini.y * all->display.line_length
					+ all->mini.x * (all->display.bits_per_pixel / 8));
			*(unsigned int *)dst = color;
			all->mini.x++;
		}
		all->mini.x -= scale;
		all->mini.y++;
	}
}

static void	draw_plr(t_all *all, int scale)
{
	t_point	plr;
	
	plr.x = all->plr.x + all->plr.dir_x;
	plr.y = all->plr.y + all->plr.dir_y;
	draw_lov(plr, all, scale);
	ft_scale_img(plr, all, 0xFF0000, scale);
}

void	draw_mini_map(t_all *all)
{
	t_point	i;
	int		scale;

	scale = WIDTH / 150;
	if (scale > 7)
		scale = 7;
	if (scale < 5)
		scale = 5;
	i.y = 0;
	while (all->map[i.y])
	{
		i.x = 0;
		while (all->map[i.y][i.x])
		{
			if (all->map[i.y][i.x] == '1')
				ft_scale_img(i, all, 0xFFFFFF, scale);
			else if (all->map[i.y][i.x] == '0')
				ft_scale_img(i, all, 0x000000, scale);
			i.x++;
		}
		i.y++;
	}
	draw_plr(all, scale);
}
