/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:37:17 by achanel           #+#    #+#             */
/*   Updated: 2022/03/30 17:39:18 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

unsigned int	get_texture_color(t_img txt, t_point point)
{
	char			*dst;
	unsigned int	color;

	dst = txt.addr + (point.y * txt.line_length
			+ point.x * (txt.bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	my_mlx_pixel_put(t_img img, t_point point, int color)
{
	char	*dst;

	dst = img.addr + (point.y * img.line_length
			+ point.x * (img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_errors(char *error_str)
{
	write(2, error_str, ft_strlen(error_str));
	exit(EXIT_FAILURE);
}
//Malloc
//File not found/invalid type
//Bad map format
//Duplicate textures
//Duplicate resolutions
//Duplicatre colors
//Bad texture file
//Bad color format
//Some keys are invalid
//Invalid main arguments
//Invalid resolution
//Invalid init