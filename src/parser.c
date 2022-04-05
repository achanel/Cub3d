/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:32:04 by rhoke             #+#    #+#             */
/*   Updated: 2022/04/04 15:24:08 by rhoke            ###   ########.fr       */
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

// void	check_parser(t_parser *pars)
// {
// 	printf("pars->NO = %s\n", pars->no);
// 	printf("pars->SO = %s\n", pars->so);
// 	printf("pars->WE = %s\n", pars->we);
// 	printf("pars->EA = %s\n", pars->ea);
// 	printf("pars->floor = %d\n", pars->floor);
// 	printf("pars->ceiling = %d\n", pars->ceiling);
// 	if (pars->map)
// 		for(int i = 0; pars->map[i]; i++)
// 			printf("pars->map[%d] = %s\n", i, pars->map[i]);
// }

int	main_parser(char **argv, t_all *all)
{
	t_list		*file;

	if (ft_strncmp((argv[1] + (ft_strlen(argv[1]) - 4)), ".cub", 4))
	{
		ft_putstr_fd("Error: Bad format map\n", 2);
		exit(EXIT_FAILURE);
	}
	file = open_file(argv[1], all->pars);
	precheck_file(file, all);
	free_list(file);
	check_map(all);
	// check_parser(pars);
	add_to_all(all);
	free_data(all->pars);
	// system("leaks parser");///
	return (0);
}
