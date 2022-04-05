/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:32:04 by rhoke             #+#    #+#             */
/*   Updated: 2022/04/05 10:47:04 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_list	*open_file(char *str, t_parser *pars)
{
	char	*line;
	int		fd;
	t_list	*file;

	line = NULL;
	file = NULL;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		error_exit();
	while (get_next_line(fd, &line))
	{
		ft_lstadd_back(&file, ft_lstnew(line));
		pars->file_size++;
	}
	ft_lstadd_back(&file, ft_lstnew(line));
	close(fd);
	return (file);
}

int	main_parser(char **argv, t_all *all)
{
	t_list		*file;

	if (WIDTH <= MINI_MAP || HEIGHT <= MINI_MAP)
		ft_errors("Error: Bad window size\n");
	if (ft_strncmp((argv[1] + (ft_strlen(argv[1]) - 4)), ".cub", 4))
	{
		ft_putstr_fd("Error: Bad format map\n", 2);
		exit(EXIT_FAILURE);
	}
	file = open_file(argv[1], all->pars);
	precheck_file(file, all);
	free_list(file);
	check_map(all);
	add_to_all(all);
	free_data(all->pars);
	return (0);
}
