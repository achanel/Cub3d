#include "cub3D.h"

<<<<<<< HEAD
void	init_mlx(t_all *all)
{
	all->win.mlx = mlx_init();
	all->win.win = mlx_new_window(all->win.mlx, WIDTH, HEIGHT, "cub3D");
}
=======
// void	ft_init_mlx(t_all *all)
// {
// 	all->win->mlx = mlx_init();
// 	all->win->win = mlx_new_window(all->win->mlx, WIDTH, HEIGHT, "cub3D");
// 	all->win->img = mlx_new_image(all->win->mlx, WIDTH, HEIGHT);
// 	all->win->addr = mlx_get_data_addr(all->win->img, &all->win->bits_per_pixel,
// 			&all->win->line_length, &all->win->endian);
// 	if (!all || !all->win->mlx)
// 		ft_errors("Invalid init");///
// }
>>>>>>> 5a7d78122034e1fa7b31cc18bd870bd12670d18f

void	init_txt(t_all *all)
{
<<<<<<< HEAD
	int	i;
	i = -1;
	while (++i < 6)
		all->txt[i].img = NULL;
	all->win.img = mlx_new_image(all->win.mlx, WIDTH, HEIGHT);
	all->win.addr = mlx_get_data_addr(all->win.img, &all->win.bits_per_pixel,
			&all->win.line_length, &all->win.endian);
=======
	int	x;
	int	y;

	y = -1;
	while (all->map[++y])
	{
		x = -1;
		while (all->map[y][++x])
		{
			if (all->map[y][x] == 'N' || all->map[y][x] == 'S'
					|| all->map[y][x] == 'W' || all->map[y][x] == 'E')
			{
				// ft_scale_img(p, all, 0x00FF00);
				break ;
			}
		}
	}
	all->plr->x = x - 3;
	all->plr->y = y - 3;
	printf("%f, %f", all->plr->x, all->plr->y);
	all->plr->dir_x = 0;
    all->plr->dir_y = 1;
    all->plr->plane_x = 0.66;
    all->plr->plane_y = 0;
	all->plr->start = 0;
	all->plr->end = 0;
	all->plr->up = 0;
	all->plr->down = 0;
	all->plr->left = 0;
	all->plr->right = 0;
>>>>>>> 5a7d78122034e1fa7b31cc18bd870bd12670d18f
}

// void	ft_init_player(t_all *all)
// {
// 	t_point	p;

// 	ft_bzero(&p, sizeof(t_point));
// 	while (all->map[++p.y])
// 	{
// 		p.x = -1;
// 		while (all->map[p.y][++p.x])
// 		{
// 			if (all->map[p.y][p.x] == 'N')
// 			{
// 				// ft_scale_img(p, all, 0x00FF00);
// 				break ;
// 			}
// 		}
// 	}
// 	all->plr->x = p.x - 3;
// 	all->plr->y = p.y - 3;
// 	all->plr->dir_x = 0;
//     all->plr->dir_y = 1;
//     all->plr->plane_x = 0.66;
//     all->plr->plane_y = 0;
// 	all->plr->start = 0;
// 	all->plr->end = 0;
// 	all->plr->up = 0;
// 	all->plr->down = 0;
// 	all->plr->left = 0;
// 	all->plr->right = 0;
// }

void	init_all(t_all *all)
{
	init_mlx(all);
	init_txt(all);
	all->map = NULL;
<<<<<<< HEAD
=======
	all->win->mlx = mlx_init();
	all->win->win = mlx_new_window(all->win->mlx, WIDTH, HEIGHT, "cub3D");
	all->win->img = mlx_new_image(all->win->mlx, WIDTH, HEIGHT);
	all->win->addr = mlx_get_data_addr(all->win->img, &all->win->bits_per_pixel,
			&all->win->line_length, &all->win->endian);
    all->colorsky = 0x00FFFF;//cian
	all->colorground = 0x340707;//choc
	all->color_east = 0xFF0000;//reddda
	all->color_west = 0x00FF00;//green
	all->color_north = 0x0000FF;//blue
	all->color_south = 0xFF00FF;//magenta
	test_parser(all);
	ft_init_player(all);
    // ft_init_mlx(all);
	return (all);
>>>>>>> 5a7d78122034e1fa7b31cc18bd870bd12670d18f
}