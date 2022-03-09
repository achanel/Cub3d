/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:56:21 by achanel           #+#    #+#             */
/*   Updated: 2022/03/09 18:01:19 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
//