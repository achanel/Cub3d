/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:14:51 by achanel           #+#    #+#             */
/*   Updated: 2022/03/09 18:04:35 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**make_map(t_list **head, int size)
{
	char	  **map = ft_calloc(size + 1, sizeof(char *));
	int		  i = -1;
	t_list	*tmp = *head;

	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	i = -1;
	while (map[++i])
		ft_putendl_fd(map[i], 1);
	return (map);
}

static void	test_parser(int ac, char **av, t_all *all)
{
	int		fd = open(av[1], O_RDONLY);
	char	*line = NULL;
	t_list	*head = NULL;

	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	make_map(&head, ft_lstsize(head));
}

static t_all	*init_all(void)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	all->map = malloc(sizeof(char **));
	all->win = malloc(sizeof(t_win));
	all->plr = malloc(sizeof(t_plr));
	all->win->mlx = NULL;
	all->win->win = NULL;
	all->map = NULL;
	return (all);
}

int	main(int ac, char **av)
{
	t_all	*all;

	if (ac != 2)
		ft_errors("Invalid main arguments\n");
	// av = NULL;
	all = init_all();
	test_parser(ac, av, all);
	all->win->mlx = mlx_init();
	all->win->win = mlx_new_window(all->win->mlx, WIDTH, HEIGHT, "cub3D");
	// if (!all || !all->win->mlx)
	// 	return (0);
	// default_values(ac, av, fractal);
	// draw_fractal(fractal);
	// mlx_key_hook(all->win->mlx_win, keyboard_hook, all);
	mlx_loop(all->win->mlx);
	return (0);
}
