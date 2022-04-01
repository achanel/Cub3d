/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:18:20 by achanel           #+#    #+#             */
/*   Updated: 2022/04/01 16:50:44 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	key_catcher(int keycode)
{
	if (keycode == W_KEY || keycode == S_KEY || keycode == A_KEY
		|| keycode == D_KEY || keycode == ARROW_LEFT || keycode == ARROW_RIGHT)
		return (1);
	return (0);
}

int	ft_exit(t_all *all)
{
	int	i;

	i = -1;
	while (++i < 6)
		mlx_destroy_image(all->win.mlx, all->txt[i].img);
	mlx_destroy_image(all->win.mlx, all->display.img);
	mlx_destroy_window(all->win.mlx, all->win.win);
	exit (0);
	return (0);
}

static int	ft_move(int keycode, t_all *all)
{
	if (keycode == W_KEY)
		all->plr.up = !all->plr.up;
	if (keycode == S_KEY)
		all->plr.down = !all->plr.down;
	if (keycode == A_KEY)
		all->plr.left = !all->plr.left;
	if (keycode == D_KEY)
		all->plr.right = !all->plr.right;
	if (keycode == ARROW_LEFT)
		all->plr.spin_l = !all->plr.spin_l;
	if (keycode == ARROW_RIGHT)
		all->plr.spin_r = !all->plr.spin_r;
	return (0);
}

int	keyboard_hook(int keycode, t_all *all)
{
	if (keycode == KEY_ESC)
		ft_exit(all);
	else if (key_catcher(keycode))
		ft_move(keycode, all);
	return (0);
}

int	loop_hook(t_all *all)
{
	if (all->mouse_flag)
		mlx_mouse_hide();
	else
		mlx_mouse_show();
	move_spin(all);
	ft_raycasting(all);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->display.img, 0, 0);
	return (0);
}
