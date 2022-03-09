/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:18:20 by achanel           #+#    #+#             */
/*   Updated: 2022/03/09 16:48:30 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_move(int keycode, t_all *all)
{
	if (keycode == ARROW_DOWN)
		all = NULL;
	// 	all->move_y += 1.1 / all->zoom;
	// else if (keycode == ARROW_UP)
	// 	all->move_y -= 1.1 / all->zoom;
	// else if (keycode == ARROW_RIGHT)
	// 	all->move_x += 1.1 / all->zoom;
	// else if (keycode == ARROW_LEFT)
	// 	all->move_x -= 1.1 / all->zoom;
	// draw_all(all);
	return (0);
}

int	keyboard_hook(int keycode, t_all *all)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT
		|| keycode == ARROW_DOWN || keycode == ARROW_UP)
		ft_move(keycode, all);
	return (0);
}