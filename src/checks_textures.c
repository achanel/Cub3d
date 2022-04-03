/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:27:39 by rhoke             #+#    #+#             */
/*   Updated: 2022/04/03 11:37:34 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*texture_link(char *str)
{
	int		j;
	char	*tex;
	int		k;
	int		i;

	i = 0;
	j = 0;
	while (str[i + j] != ' ' && str[i + j])
		j++;
	tex = (char *)malloc(sizeof(char) * (j + 1));
	malloc_error(tex);
	k = 0;
	while (k < j)
	{
		tex[k] = str[i + k];
		k++;
	}
	tex[k] = '\0';
	i += j;
	return (tex);
}

void	error_color(char **arr, t_parser *pars)
{
	for_free(arr);
	file_error(pars);
}

void	check_link(char *str, t_parser *pars)
{
	int		fd;
	char	*format;
	int		i;

	i = 0;
	format = str + (ft_strlen(str) - 4);
	fd = open(str, O_RDONLY);
	if (fd == -1 || ft_strncmp(format, ".xpm", 4) != 0)
	{
		link_error(pars);
	}
	close(fd);
}

void	check_textures(t_parser *pars)
{
	if (pars->no)
		check_link(pars->no, pars);
	if (pars->so)
		check_link(pars->so, pars);
	if (pars->we)
		check_link(pars->we, pars);
	if (pars->ea)
		check_link(pars->ea, pars);
}
