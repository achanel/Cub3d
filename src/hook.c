/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:18:20 by achanel           #+#    #+#             */
/*   Updated: 2022/03/11 19:05:55 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static int	ft_move(int keycode, t_all *all)
// {
// 	mlx_clear_window(all->win->mlx, all->win->win);
// 	if (keycode == W_KEY)
// 	{
// 		all->plr->y += sin(all->plr->dir) * 4;
// 		all->plr->x += cos(all->plr->dir) * 4;
// 	}
// 	if (keycode == S_KEY)
// 	{
// 		all->plr->y -= sin(all->plr->dir) * 4;
// 		all->plr->x -= cos(all->plr->dir) * 4;
// 	}
// 	if (keycode == 0)
// 		all->plr->dir -= 0.1;
// 	if (keycode == 2)
// 		all->plr->dir += 0.1;
// 	draw_screen(all);
// 	return (0);
// }

static int	ft_move(int keycode, t_all *all)
{
	if (keycode == W_KEY)
		--all->plr->y;
	if (keycode == S_KEY)
		++all->plr->y;
	if (keycode == 0)
		--all->plr->x;
	if (keycode == 2)
		++all->plr->x;
	// mlx_destroy_image(all->win->mlx, all->win->img);
	// mlx_clear_window(all->win->mlx, all->win->win);
	draw_screen(all);
	printf("here\n");
	return (0);
}

int	keyboard_hook(int keycode, t_all *all)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == W_KEY || keycode == S_KEY
		|| keycode == A_KEY || keycode == D_KEY)
		ft_move(keycode, all);
	return (0);
}
