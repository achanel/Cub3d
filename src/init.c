/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:00:36 by achanel           #+#    #+#             */
/*   Updated: 2022/04/05 12:48:57 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	player_data(char c, t_all *all, int i, int j)
{
	if (c == 'N')
		all->plr.angle = 3 * M_PI_2;
	else if (c == 'S')
		all->plr.angle = M_PI_2;
	else if (c == 'W')
		all->plr.angle = 0;
	else if (c == 'E')
		all->plr.angle = M_PI;
	all->plr.y = j + 0.5;
	all->plr.x = i + 0.5;
	all->plr.up = 0;
	all->plr.down = 0;
	all->plr.left = 0;
	all->plr.right = 0;
	all->plr.spin_l = 0;
	all->plr.spin_r = 0;
}

void	make_plr(t_all *all)
{
	int	i;
	int	j;

	j = -1;
	while (all->map[++j])
	{
		i = -1;
		while (all->map[j][++i])
		{
			if (is_player_char(all->map[j][i]))
			{
				if (all->plr.x == 0 || all->plr.y == 0 || all->plr.angle == 0)
					player_data(all->map[j][i], all, i, j);
				else
				{	
					ft_putstr_fd("Bad player point\n", 2);
					exit(EXIT_FAILURE);
				}
				all->map[j][i] = '0';
			}
		}
	}
}

static void	add_img(char *texture, t_all *all, int index)
{
	t_img	img;

	img = all->txt[index];
	img.img = mlx_xpm_file_to_image(all->win.mlx, texture, &img.w, &img.h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	all->txt[index] = img;
}

static void	add_rgb(t_all *all, int index)
{
	t_img	img;
	t_point	p;

	p.y = 0;
	p.x = 0;
	img.img = mlx_new_image(all->win.mlx, 1, 1);
	img.h = 1;
	img.w = 1;
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	all->txt[index] = img;
}

void	add_to_all(t_all *all)
{
	int	i;

	i = -1;
	add_rgb(all, FLOOR);
	add_rgb(all, CELLING);
	add_img(all->pars->no, all, NORTH);
	add_img(all->pars->so, all, SOUTH);
	add_img(all->pars->we, all, WEST);
	add_img(all->pars->ea, all, EAST);
	make_plr(all);
	if (all->pars->map_size > HEIGHT / 3)
		all->mini_flag = 0;
	while (all->map[++i])
		if (ft_strlen(all->map[i]) > WIDTH / 6)
			all->mini_flag = 0;
}
