/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:25:54 by rhoke             #+#    #+#             */
/*   Updated: 2022/04/03 13:21:23 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_str(char *tmp, t_all *all)
{
	int		i;
	char	*str;

	str = ft_strdup(tmp);
	i = 0;
	if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W'
		|| str[i] == 'E' || str[i] == 'F' || str[i] == 'C'
		|| str[i] == ' ' || str[i] == '1' || str[i] == '0'
		|| !ft_strlen(str))
	{
		fill_struct(all, str);
		free(str);
		return (1);
	}
	return (1);
}

void	precheck_file(t_list *file, t_all *all)
{
	t_list	*tmp;
	char	*str;
	int		i;

	tmp = file;
	while (tmp)
	{
		str = ft_strdup((char *)tmp->content);
		i = 0;
		if (!check_str(str, all))
		{
			break ;
		}
		tmp = tmp->next;
		free(str);
	}
}
