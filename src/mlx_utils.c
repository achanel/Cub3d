/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:10:53 by achanel           #+#    #+#             */
/*   Updated: 2022/03/11 16:27:09 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_all *all, t_point point, int color)
{
	char	*dst;

	dst = all->win->addr + (point.y * all->win->line_length + point.x
			* (all->win->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

