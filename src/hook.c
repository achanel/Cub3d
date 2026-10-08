/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:18:20 by achanel           #+#    #+#             */
/*   Updated: 2022/04/06 12:00:00 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_exit(t_all *all)
{
	int	i;

	i = -1;
	while (++i < TEX_COUNT)
		if (all->txt[i].img)
			mlx_destroy_image(all->win.mlx, all->txt[i].img);
	if (all->display.img)
		mlx_destroy_image(all->win.mlx, all->display.img);
	mlx_destroy_window(all->win.mlx, all->win.win);
	exit (0);
	return (0);
}

static void	set_move(int keycode, t_all *all, int value)
{
	if (keycode == W_KEY)
		all->plr.up = value;
	else if (keycode == S_KEY)
		all->plr.down = value;
	else if (keycode == A_KEY)
		all->plr.left = value;
	else if (keycode == D_KEY)
		all->plr.right = value;
	else if (keycode == ARROW_LEFT)
		all->plr.spin_l = value;
	else if (keycode == ARROW_RIGHT)
		all->plr.spin_r = value;
}

int	key_press(int keycode, t_all *all)
{
	if (keycode == KEY_ESC)
		ft_exit(all);
	else if (keycode == E_KEY || keycode == SPACE_KEY)
		toggle_door(all);
	else
		set_move(keycode, all, 1);
	return (0);
}

int	key_release(int keycode, t_all *all)
{
	set_move(keycode, all, 0);
	return (0);
}

int	loop_hook(t_all *all)
{
	if (all->mouse_flag)
		mlx_mouse_hide();
	else
		mlx_mouse_show();
	move_spin(all);
	update_doors(all);
	collect_sprites(all);
	all->timer++;
	all->frame = (all->timer / ANIM_SPEED) % SPRITE_FRAMES;
	ft_raycasting(all);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->display.img, 0, 0);
	return (0);
}
