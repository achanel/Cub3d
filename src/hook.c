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

int	ft_exit(t_all *all)
{
	mlx_destroy_image(all->win->mlx, all->win->img);
	mlx_destroy_window(all->win->mlx, all->win->win);
	exit (0);
	return (0);
}

static int	ft_move(int keycode, t_all *all)
{
	if (keycode == W_KEY)
		all->plr->up = !all->plr->up;
	if (keycode == S_KEY)
		all->plr->down = !all->plr->down;
	if (keycode == A_KEY)
		all->plr->left = !all->plr->left;
	if (keycode == D_KEY)
		all->plr->right = !all->plr->right;
	// mlx_destroy_image(all->win->mlx, all->win->img);
	// mlx_clear_window(all->win->mlx, all->win->win);
	// draw_screen(all);
	// printf("here\n");
	return (0);
}

int	keyboard_hook(int keycode, t_all *all)
{
	if (keycode == KEY_ESC)
		ft_exit(all);
	else if (keycode == W_KEY || keycode == S_KEY
		|| keycode == A_KEY || keycode == D_KEY)
		ft_move(keycode, all);
	return (0);
}
