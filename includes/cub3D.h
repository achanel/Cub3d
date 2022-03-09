/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:20:05 by achanel           #+#    #+#             */
/*   Updated: 2022/03/09 18:01:34 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include "../libft/libft.h"
# define WIDTH 1000
# define HEIGHT 1000
# define BUFFER_SIZE 1000
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define KEY_ESC 53
# define SCALE 16 // условный размер каждого квадратика в карте

typedef struct s_win //структура для окна
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			line_length;
	int			bits_per_pixel;
	int			endian;
}	t_win;

typedef struct s_point // структура для точки
{
	int			x;
	int			y;
}	t_point;

typedef struct s_plr //структура для игрока и луча
{
	float		x;
	float		y;
	float		dir;
	float		start;
	float		end;
}	t_plr;

typedef struct s_all // структура для всего вместе
{
	t_win		*win;
	t_plr		*plr;
	char		**map;
}	t_all;
//gnl
int		get_next_line(int fd, char **line);
//hooks
int		keyboard_hook(int keycode, t_all *all);
//utils
void	ft_errors(char *error_str);

#endif