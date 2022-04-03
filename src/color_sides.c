/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_sides.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:30:18 by rhoke             #+#    #+#             */
/*   Updated: 2022/04/03 11:37:36 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	arr_size(char **arr)
{
	int	size;

	size = 0;
	while (arr[size])
		size++;
	return (size);
}

int	create_rgb(int r, int g, int b)
{
	if ((r < 0 || r > 255) || (g < 0 || g > 255)
		|| (b < 0 || b > 255))
		return (-1);
	return (r << 16 | g << 8 | b);
}

int	color_font(char *str, t_parser *pars)
{
	char	*c_str;
	char	**arr;
	int		color;

	c_str = texture_link(str);
	arr = ft_split(c_str, ',');
	free(c_str);
	if (arr_size(arr) != 3)
		error_color(arr, pars);
	color = create_rgb(ft_atoi(arr[0]),
			ft_atoi(arr[1]),
			ft_atoi(arr[2]));
	if (color < 0)
		error_color(arr, pars);
	for_free(arr);
	return (color);
}

void	floor_color(t_parser *pars, char **str)
{
	if (ft_strnstr("F", str[0], 1) && !str[2])
	{
		pars->floor = color_font(str[1], pars);
	}
	else
		file_error(pars);
}

void	ceilling_color(t_parser *pars, char **str)
{
	if (ft_strnstr("C", str[0], 1) && !str[2])
	{
		pars->ceiling = color_font(str[1], pars);
	}
	else
		file_error(pars);
}
