/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:37:21 by rhoke             #+#    #+#             */
/*   Updated: 2022/04/03 17:49:59 by rhoke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	no_side(t_parser *pars, char **str)
{
	if (ft_strnstr("NO", str[0], 2) && !str[2])
	{
		pars->no = ft_strdup(str[1]);
	}
	else
		file_error(pars);
}

void	so_side(t_parser *pars, char **str)
{
	if (ft_strnstr("SO", str[0], 2) && !str[2])
	{
		pars->so = ft_strdup(str[1]);
	}
	else
		file_error(pars);
}

void	we_side(t_parser *pars, char **str)
{
	if (ft_strnstr("WE", str[0], 2) && !str[2])
	{
		pars->we = ft_strdup(str[1]);
	}
	else
		file_error(pars);
}

void	ea_side(t_parser *pars, char **str)
{
	if (ft_strnstr("EA", str[0], 2) && !str[2])
	{
		pars->ea = ft_strdup(str[1]);
	}
	else
		file_error(pars);
}

void	fill_struct(t_all *all, char *str)
{
	char	**str1;

	str1 = NULL;
	if (!all->pars->no || !all->pars->so || !all->pars->we || !all->pars->ea
		|| all->floor == -1 || all->ceilling == -1)
	{
		if (!ft_strlen(str))
			return ;
		str1 = ft_split(str, ' ');
		if (ft_strnstr("NO", str1[0], 2))
			no_side(all->pars, str1);
		if (ft_strnstr("SO", str1[0], 2))
			so_side(all->pars, str1);
		if (ft_strnstr("WE", str1[0], 2))
			we_side(all->pars, str1);
		if (ft_strnstr("EA", str1[0], 2))
			ea_side(all->pars, str1);
		if (ft_strnstr("F", str1[0], 1))
			floor_color(all, str1);
		if (ft_strnstr("C", str1[0], 1))
			ceilling_color(all, str1);
		for_free(str1);
	}
	else
		fill_map(all, str);
}
