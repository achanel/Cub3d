/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:14:51 by achanel           #+#    #+#             */
/*   Updated: 2022/03/11 19:03:33 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_all	all;

	init_all(&all);
	test_parser(av[1], &all);
	mlx_do_key_autorepeatoff(all.win.mlx);
	mlx_key_hook(all.win.win, keyboard_hook, &all);
	mlx_hook(all.win.win, 2, 1L<<0, keyboard_hook, &all);
	mlx_hook(all.win.win, 17, 18, ft_exit, &all);
    mlx_loop_hook(all.win.mlx, loop_hook, &all);
	mlx_loop(all.win.mlx);
	return (0);
}
