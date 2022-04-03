/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:26:59 by rhoke             #+#    #+#             */
/*   Updated: 2022/04/03 13:31:09 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	if_space_error(t_all *all, int i, int j)
{
	if (all->map[i][j] != ' ' && all->map[i][j] != '1')
		map_error(all->pars);
}

void	check_if_space_correct(t_all *all, int i, int j)
{
	if (i != 0)
	{
		if (j != 0 && ft_strlen(all->map[i - 1]) > j - 1)
			if_space_error(all, i - 1, j - 1);
		if (ft_strlen(all->map[i - 1]) > j)
			if_space_error(all, i - 1, j);
		if (ft_strlen(all->map[i - 1]) > j + 1)
			if_space_error(all, i - 1, j + 1);
	}
	if (j != 0)
	{
		if_space_error(all, i, j - 1);
		if (all->map[i + 1])
			if_space_error(all, i + 1, j - 1);
	}
	if (all->map[i + 1])
	{
		if_space_error(all, i + 1, j);
		if (ft_strlen(all->map[i + 1]) > j + 1)
			if_space_error(all, i + 1, j + 1);
	}
	if (ft_strlen(all->map[i]) > j + 1)
		if_space_error(all, i, j + 1);
}

void	if_space_in_map(t_all *all, int i, int j)
{
	if (all->map[i][j] == ' ')
		check_if_space_correct(all, i, j);
}

void	check_map(t_all *all)
{
	if (!all->map || !all->pars->no || !all->pars->so || !all->pars->we || !all->pars->ea
		|| all->pars->floor == -1 || all->pars->ceiling == -1)
		file_error(all->pars);
	else
	{
		while (all->map[all->pars->map_size])
			all->pars->map_size++;
		check_borders(all);
		validate_map(all);
	}
}
