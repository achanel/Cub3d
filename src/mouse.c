/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:54:00 by achanel           #+#    #+#             */
/*   Updated: 2022/03/28 14:07:33 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mouse_move(int x, int y, t_all *all)
{
	(void)y;
	all->mouse_x = x;
	mlx_mouse_move(all->win.win, WIDTH / 2, HEIGHT / 2);
	return (0);
}