/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:40:20 by rhoke             #+#    #+#             */
/*   Updated: 2022/04/05 09:48:52 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_zero(t_all *all, int i, int j)
{
	if ((all->map[i - 1][j - 1] == '1'
		|| all->map[i - 1][j - 1] == '0') && (all->map[i][j - 1] == '1'
		|| all->map[i][j - 1] == '0') && (all->map[i + 1][j + 1] == '1'
		|| all->map[i + 1][j + 1] == '0') && (all->map[i - 1][j + 1] == '1'
		|| all->map[i - 1][j + 1] == '0') && (all->map[i - 1][j] == '1'
		|| all->map[i - 1][j] == '0') && (all->map[i + 1][j] == '1'
		|| all->map[i + 1][j] == '0') && (all->map[i + 1][j - 1] == '1'
		|| all->map[i + 1][j - 1] == '0') && (all->map[i][j + 1] == '1'
		|| all->map[i][j + 1] == '0'))
		return ;
	else
	{
		ft_putstr_fd("lol", 1);
		map_error(all->pars);
	}
}

void	map_spaces(t_all *all, int i, int j)
{
	if (all->map[i][j] != ' ' && all->map[i][j] != '1' &&
		all->map[i][j] != '0' && all->map[i][j] != 'N' &&
		all->map[i][j] != 'S' && all->map[i][j] != 'E' &&
		all->map[i][j] != 'W')
		map_error(all->pars);
	else
		if_space_in_map(all, i, j);
}

void	validate_map(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
		{
			map_spaces(all, i, j);
			if (all->map[i][j] == '0')
				check_zero(all, i, j);
			j++;
		}
		i++;
	}
}

void	check_borders_top_bottom(t_all *all)
{
	int	i;

	i = 0;
	while (all->map[0][i])
	{
		if (ft_strlen(all->map[0]) < ft_strlen(all->map[1])
			&& (all->map[1][ft_strlen(all->map[0]) - 1] == '0'
			|| all->map[1][ft_strlen(all->map[0]) + 1] == '0'))
			map_error(all->pars);
		if_space_error(all, 0, i);
		if_space_in_map(all, 0, i);
		i++;
	}
	i = 0;
	while (all->map[all->pars->map_size - 1][i])
	{
		if_space_error(all, all->pars->map_size - 1, i);
		if_space_in_map(all, all->pars->map_size - 1, i);
		i++;
	}
}

void	check_borders_left_right(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->pars->map_size)
	{
		if_space_error(all, i, 0);
		if_space_in_map(all, i, 0);
		i++;
	}
	i = 0;
	while (i < all->pars->map_size)
	{
		if_space_error(all, i, ft_strlen(all->map[i]) - 1);
		if_space_in_map(all, i, ft_strlen(all->map[i]) - 1);
		i++;
	}
}
