/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_for_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:30:25 by rhoke             #+#    #+#             */
/*   Updated: 2022/04/03 13:12:27 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_parser	*pars_init(void)
{
	t_parser	*pars;
	t_player	pl;

	pars = (t_parser *)malloc(sizeof(t_parser));
	if (!pars)
		error_exit();
	pars->ceiling = -1;
	pars->floor = -1;
	pars->ea = NULL;
	pars->no = NULL;
	pars->so = NULL;
	pars->we = NULL;
	pars->map_size = 0;
	pars->file_size = 0;
	pars->i = -1;
	pars->j = -1;
	pl.x = -1;
	pl.y = -1;
	pl.orient = -1;
	return (pars);
}

void	free_list(t_list *list)
{
	t_list	*tmp;

	if (!list)
		return ;
	while (list)
	{
		tmp = list->next;
		free(list->content);
		free(list);
		list = tmp;
	}
}

void	free_data(t_parser *pars)
{
	free(pars->no);
	free(pars->so);
	free(pars->we);
	free(pars->ea);
	// if (pars->map)
	// 	for_free(pars->map);
	free(pars);
}
