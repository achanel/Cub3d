/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:14:51 by achanel           #+#    #+#             */
/*   Updated: 2022/04/05 10:12:27 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_mlx(t_all *all)
{
	all->win.mlx = mlx_init();
	if (!all->win.mlx)
		ft_errors("Error: mlx init\n");
	all->win.win = mlx_new_window(all->win.mlx, WIDTH, HEIGHT, "cub3D");
	if (!all->win.win)
		ft_errors("Error: mlx window init\n");
}

void	init_txt(t_all *all)
{
	int	i;

	i = -1;
	while (++i < TEX_COUNT)
	{
		all->txt[i].img = NULL;
		all->txt[i].addr = NULL;
		all->txt[i].w = 0;
		all->txt[i].h = 0;
	}
	all->display.img = mlx_new_image(all->win.mlx, WIDTH, HEIGHT);
	if (!all->display.img)
	{
		mlx_destroy_window(all->win.mlx, all->win.win);
		ft_errors("Error: image init\n");
	}
	all->display.w = WIDTH;
	all->display.h = HEIGHT;
	all->display.addr = mlx_get_data_addr(all->display.img,
			&all->display.bits_per_pixel, &all->display.line_length,
			&all->display.endian);
}

void	init_all(t_all *all)
{
	all->plr.x = 0;
	all->plr.y = 0;
	all->plr.angle = 0;
	all->plr.dir_x = 0;
	all->plr.dir_y = 0;
	all->pars = pars_init();
	init_mlx(all);
	init_txt(all);
	all->map = NULL;
	all->mouse_x = WIDTH / 2;
	all->mouse_flag = 1;
	all->ceilling = -1;
	all->floor = -1;
	all->mini_flag = 1;
	all->crosshair = 1;
	all->frame = 0;
	all->timer = 0;
	all->map_h = 0;
	all->door_count = 0;
	all->sprite_count = 0;
	all->sprite_transp = 0x00FF00FF;
}

int	main(int ac, char **av)
{
	t_all	all;

	if (ac != 2)
		ft_errors("Error: Bad number of arguments\n");
	init_all(&all);
	main_parser(av, &all);
	mlx_do_key_autorepeatoff(all.win.mlx);
	mlx_hook(all.win.win, 2, 1L << 0, key_press, &all);
	mlx_hook(all.win.win, 3, 1L << 1, key_release, &all);
	mlx_hook(all.win.win, 6, 0, mouse_move, &all);
	mlx_hook(all.win.win, 5, 0, mouse_relese, &all);
	mlx_hook(all.win.win, 17, 18, ft_exit, &all);
	mlx_loop_hook(all.win.mlx, loop_hook, &all);
	mlx_loop(all.win.mlx);
	return (0);
}
