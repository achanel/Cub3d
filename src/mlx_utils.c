/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:10:53 by achanel           #+#    #+#             */
/*   Updated: 2022/03/16 19:14:20 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

<<<<<<< HEAD
unsigned int	get_texture_color(t_txt txt, t_point point)
{
	char			*dst;
	unsigned int	color;

	dst = txt.addr + (point.y * txt.line_length + point.x * (txt.bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	my_mlx_pixel_put(t_win img, t_point point, int color)
=======
void	fill_pixel(char **img, t_point pixel, int color)
{
	if (pixel.x < WIDTH && pixel.y < HEIGHT && pixel.x >= 0 && pixel.y >= 0)
	{
		((int*)*img)[pixel.x + (pixel.y * WIDTH)] = color;
	}
}

void	my_mlx_pixel_put(t_all *all, t_point point, int color)
>>>>>>> 5a7d78122034e1fa7b31cc18bd870bd12670d18f
{
	char	*dst;

	dst = img.addr + (point.y * img.line_length + point.x * (img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	loop_hook(t_all *all)
{
	if (all->plr.up)
		move_up(all);
	if (all->plr.down)
		move_down(all);
	if (all->plr.left)
		move_left(all);
	if (all->plr.right)
		move_right(all);
	ft_raycasting(all);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->win.img, 0, 0);
	return (0);
}
