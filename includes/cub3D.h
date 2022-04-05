/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:20:05 by achanel           #+#    #+#             */
/*   Updated: 2022/04/05 11:39:51 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "mlx.h"
# include "../libft/includes/libft.h"
# define WIDTH 1040
# define HEIGHT 720
# define MINI_MAP 150

# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define MV_SPEED 0.05
# define ROT_SPEED 0.03
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define KEY_ESC 53

# define HITBOX 0.3
# define MOUSE 0.00065

# define WE 0
# define NS 1
# define NORTH 2
# define SOUTH 3
# define WEST 4
# define EAST 5

# define FLOOR 0
# define CELLING 1

typedef struct s_win
{
	void		*mlx;
	void		*win;
}	t_win;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			line_length;
	int			bits_per_pixel;
	int			endian;
	int			w;
	int			h;
}	t_img;

typedef struct s_point
{
	int			x;
	int			y;
}	t_point;

typedef struct s_plr
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
	int			spin_l;
	int			spin_r;
	float		angle;
}	t_plr;

typedef struct s_ray
{
	float		posx;
	float		posy;
	float		dirx;
	float		diry;
	float		sidedx;
	float		sidedy;
	float		ddistx;
	float		ddisty;
	float		walldist;
	int			side;
	int			stepx;
	int			stepy;
	float		camerax;
	int			mapx;
	int			mapy;
	float		draw_start;
	float		draw_end;
	float		ray_r;
	float		plane_x;
	float		plane_y;
	int			hit;
	int			line_height;
	float		wall_x;
	int			tex;
	float		tex_stepy;
	float		tex_stepx;
	float		tex_pos;
	int			tex_x;
	int			tex_y;
	int			pix_x;
}				t_ray;

typedef struct s_map
{
	int	x;
	int	y;
	int	x_end;
	int	y_end;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	orient;
}				t_player;

typedef struct s_parser
{
	int			floor;
	int			ceiling;
	int			j;
	int			i;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			map_size;
	int			file_size;
	t_player	p;
}				t_parser;

typedef struct s_all
{
	t_win		win;
	t_plr		plr;
	t_img		txt[6];
	t_img		display;
	t_map		mini;
	t_parser	*pars;
	char		**map;
	int			mouse_x;	
	int			mouse_flag;
	int			ceilling;
	int			floor;
	int			mini_flag;
}	t_all;

//draw
void			draw_line(t_all *all, t_ray *ray, int x);
//hook
int				ft_exit(t_all *all);
int				keyboard_hook(int keycode, t_all *all);
int				loop_hook(t_all *all);
//moves
void			move_spin(t_all *all);
//raycasting
void			ft_raycasting(t_all *all);
//utils
void			for_free(char **new);
int				is_player_char(char c);
void			ft_errors(char *error_str);
unsigned int	get_texture_color(t_img txt, t_point point);
void			my_mlx_pixel_put(t_img img, t_point point, int color);
//mini_map
void			draw_mini_map(t_all *all);
//mouse_move
int				mouse_relese(int keykode, int x, int y, t_all *all);
int				mouse_move(int x, int y, t_all *all);
//parser
int				main_parser(char **argv, t_all *all);

void			precheck_file(t_list *file, t_all *all);
// walls.c
void			fill_struct(t_all *all, char *str);
// walls_utils.c
char			*texture_link(char *str);
void			check_after_link(t_parser *pars, char *str);
// errors.c
void			file_error(t_parser *pars);
void			link_error(t_parser *pars);
void			malloc_error(void *ptr);
void			error_exit(void);
void			map_error(t_parser *pars);
// fts_for_struct.c
t_parser		*pars_init(void);
void			free_list(t_list *list);
void			free_data(t_parser *pars);

// color_sides.c
void			error_color(char **arr, t_parser *pars);
int				color_font(char *str, t_parser *pars);
void			floor_color(t_all *pars, char **str);
void			ceilling_color(t_all *pars, char **str);
// map.c
void			fill_map(t_all *all, char *str);
// checks_textures.c
char			*texture_link(char *str);
void			check_textures(t_parser *pars);
// check_map.c
void			check_borders(t_all *all);
void			if_space_error(t_all *all, int i, int j);
void			if_space_in_map(t_all *all, int i, int j);
void			check_map(t_all *all);
// borders.c
void			validate_map(t_all *all);
void			map_spaces(t_all *all, int i, int j);
void			check_borders_top_bottom(t_all *all);
void			check_borders_left_right(t_all *all);
// src
void			add_to_all(t_all *all);
// init
void			player_data(char c, t_all *all, int i, int j);
void			make_plr(t_all *all);
#endif