/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:14:51 by achanel           #+#    #+#             */
/*   Updated: 2022/03/16 19:33:17 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	ft_draw_player(t_all *all)
// {
// 	t_point	p_end;
// 	t_point	tmp;
// 	tmp.x = all->plr->x;
// 	tmp.y = all->plr->y;

// 	// printf("%f %f\n", tmp.x, tmp.y);
// 	ft_bzero(&p_end, sizeof(t_point));
// 	p_end.x = (tmp.x + 1) * SCALE;
// 	p_end.y = (tmp.y + 1) * SCALE;
// 	tmp.x *= SCALE;
// 	tmp.y *= SCALE;
// 	while (tmp.y < p_end.y)
// 	{
// 		while (tmp.x < p_end.x)
// 		{
// 			// my_mlx_pixel_put(all, tmp, 0xFFFF00);
// 			tmp.x++;
// 		}
// 		tmp.x -= SCALE;
// 		tmp.y++;
// 	}
// }

// void	ft_scale_img(t_point point, t_all *all, int color)
// {
// 	t_point	end;

// 	ft_bzero(&end, sizeof(t_point));
// 	end.x = (point.x + 1) * SCALE;
// 	end.y = (point.y + 1) * SCALE;
// 	point.x *= SCALE;
// 	point.y *= SCALE;
// 	while (point.y < end.y)
// 	{
// 		while (point.x < end.x)
// 		{
// 			// my_mlx_pixel_put(all, point, color);
// 			point.x++;
// 		}
// 		point.x -= SCALE;
// 		point.y++;
// 	}
// }

// // void	draw_screen(t_all *all)
// // {
// // 	t_point	point;

// // 	ft_bzero(&point, sizeof(t_point));
// // 	while (all->map[point.y])
// // 	{
// // 		point.x = 0;
// // 		while (all->map[point.y][point.x])
// // 		{
// // 			if (all->map[point.y][point.x] == '1')
// // 				ft_scale_img(point, all, 0xFFFFFF);
// // 			else
// // 				ft_scale_img(point, all, 0x000000);
// // 			point.x++;
// // 		}
// // 		point.y++;
// // 	}
// // 	printf("%f %f\n", all->plr->x, all->plr->y);
// // 	ft_draw_player(all);
// // 	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
// // }

void	make_map(t_all *all, t_list **head, int size)
{
	int		  i = -1;
	t_list	*tmp = *head;

	all->map = ft_calloc(size + 1, sizeof(char *));
	while (tmp)
	{
		all->map[++i] = tmp->content;
		tmp = tmp->next;
	}
	i = -1;
	// while (all->map[++i])
	// 	ft_putendl_fd(all->map[i], 1);
	// return (all->map);
}

void	test_parser(t_all *all)
{
	int		fd = open("./maps/map.cub", O_RDONLY);
	char	*line = NULL;
	t_list	*head = NULL;

	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	make_map(all, &head, ft_lstsize(head));
}

int	main(int ac, char **av)
{
	t_all	*all;

	// if (ac != 2)
	// 	ft_errors("Invalid main arguments\n");
	all = init_all();
	// draw_screen(all);
	mlx_do_key_autorepeatoff(all->win->mlx);
	mlx_key_hook(all->win->win, keyboard_hook, all);
	mlx_hook(all->win->win, 2, 1L<<0, keyboard_hook, all);
	mlx_hook(all->win->win, 17, 18, ft_exit, all);
    mlx_loop_hook(all->win->mlx, loop_hook, all);
	mlx_loop(all->win->mlx);
	return (0);
}
