/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:30:12 by rhoke             #+#    #+#             */
/*   Updated: 2022/04/05 09:47:47 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	file_error(t_parser *pars)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Data from the file is incorrect\n", 2);
	free_data(pars);
	exit(EXIT_FAILURE);
}

void	link_error(t_parser *pars)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Link for a texture is incorrect\n", 2);
	free_data(pars);
	exit(EXIT_FAILURE);
}

void	malloc_error(void *ptr)
{
	if (ptr == NULL)
	{
		ft_putstr_fd("Error with malloc\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	error_exit(void)
{
	ft_putstr_fd(strerror(errno), 2);
	exit(EXIT_FAILURE);
}

void	map_error(t_parser *pars)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Data of the map is incorrect\n", 2);
	free_data(pars);
	exit(EXIT_FAILURE);
}
