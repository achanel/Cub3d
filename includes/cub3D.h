/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:20:05 by achanel           #+#    #+#             */
/*   Updated: 2022/03/16 17:05:18 by achanel          ###   ########.fr       */
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
# define WIDTH 800
# define HEIGHT 600
# define MINI_MAPW 160
# define MINI_MAPH 160
# define SQUARE_MAP_SIZE 20
# define BUFFER_SIZE 1000
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define MV_SPEED 0.03
# define ROT_SPEED 0.03
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define KEY_ESC 53
# define SCALE 16 // условный размер каждого квадратика в карте

typedef struct s_win //структура для окна
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
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
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
	float		start;
	float		end;
	int			up;
	int			down;
	int			left;
	int			right;
}	t_plr;

typedef struct	s_ray
{
	double		posx;
	double		posy;

	double		dirx;
	double		diry;

	double		sidedx;
	double		sidedy;

	double		ddistx;
	double		ddisty;

	double		walldist;

	int			side;

	int			stepx;
	int			stepy;

	double		camerax;

	int			mapx;
	int			mapy;
	double		draw_start;
	double		draw_end;

}				t_ray;

typedef struct	s_draw
{
	int			color;
	int			zi;
	int			zf;
	int			xi;
	int			yi;
	int			xf;
	int			yf;
	int			dx;
	int			dy;
	int			xinc;
	int			yinc;
	int			decalx;
	int			decaly;
	int			offsetx;
	int			offsety;
}				t_draw;

typedef struct s_all // структура для всего вместе
{
	t_win		*win;
	t_plr		*plr;
	char		**map;
	int			colorsky;
	int			colorground;
	int			color_east;
	int			color_west;
	int			color_north;
	int			color_south;
}	t_all;
//main
void	ft_scale_img(t_point point, t_all *all, int color);
void	test_parser(t_all *all);
// void	draw_screen(t_all *all);
//gnl
int		get_next_line(int fd, char **line);
//hooks
int		ft_exit(t_all *all);
int		keyboard_hook(int keycode, t_all *all);
//utils
void	ft_errors(char *error_str);
//mlx_utils
void	fill_pixel(char **img, t_point pixel, int color);
void	my_mlx_pixel_put(t_all *all, t_point point, int color);
int		loop_hook(t_all *all);
//raycasting
void    ft_raycasting(t_all *all);
//ray
void		draw_ray(t_all *all, double xf, double yf, int color);
//draw
void		draw_line(t_all *all, t_ray *ray, int x);
//moves
void	move_up(t_all *all);
void	move_down(t_all *all);
void	move_right(t_all *all);
void	move_left(t_all *all);
//init
t_all	*init_all(void);

#endif