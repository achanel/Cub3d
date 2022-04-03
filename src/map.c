/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:31:57 by rhoke             #+#    #+#             */
/*   Updated: 2022/04/03 13:23:35 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	arr_to_list_sp(char *str, t_all *all)
{
	if (ft_strlen(str))
	{
		all->map[++all->pars->i] = ft_strdup(str);
	}
	else
		all->map[all->pars->i++] = NULL;
}

void	fill_map(t_all *all, char *str)
{
	int	i;

	i = 0;
	if (!all->map)
		all->map = (char **)malloc(sizeof(char *) * (all->pars->file_size));
	malloc_error(all->map);
	check_textures(all->pars);
	if (ft_strlen(str))
	{
		if (str[i] == '1' || str[i] == '0' || str[i] == ' ')
		{
			arr_to_list_sp(str, all);
		}
	}
	else if (!ft_strlen(str) && all->pars->i > 0)
	{	
		map_error(all->pars);
		return ;
	}
}
