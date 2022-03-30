/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:53:44 by achanel           #+#    #+#             */
/*   Updated: 2022/03/30 17:47:03 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	
	plr.x = all->plr.x;
	plr.y = all->plr.y;
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
