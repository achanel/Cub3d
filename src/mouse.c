/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:54:00 by achanel           #+#    #+#             */
/*   Updated: 2022/04/01 16:51:27 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mouse_relese(int keykode, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	if (keykode == 1)
		all->mouse_flag = !all->mouse_flag;
	return (0);
}

int	mouse_move(int x, int y, t_all *all)
{
	(void)y;
	all->mouse_x = x;
	if (all->mouse_flag)
		mlx_mouse_move(all->win.win, WIDTH / 2, HEIGHT / 2);
	return (0);
}
