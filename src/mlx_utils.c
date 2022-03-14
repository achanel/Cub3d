/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:10:53 by achanel           #+#    #+#             */
/*   Updated: 2022/03/11 16:27:09 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_all *all, t_point point, int color)
{
	char	*dst;

	dst = all->win->addr + (point.y * all->win->line_length + point.x
			* (all->win->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	loop_hook(t_all *all)
{
	if (all->plr->up)
		move_up(all);
	if (all->plr->down)
		move_down(all);
	if (all->plr->left)
		move_left(all);
	if (all->plr->right)
		move_right(all);
	ft_raycasting(all);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
	return (0);
}
