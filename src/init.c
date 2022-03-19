#include "cub3D.h"

void	init_mlx(t_all *all)
{
	all->win.mlx = mlx_init();
	all->win.win = mlx_new_window(all->win.mlx, WIDTH, HEIGHT, "cub3D");
}

void	init_txt(t_all *all)
{
	int	i;
	i = -1;
	while (++i < 6)
		all->txt[i].img = NULL;
	all->win.img = mlx_new_image(all->win.mlx, WIDTH, HEIGHT);
	all->win.addr = mlx_get_data_addr(all->win.img, &all->win.bits_per_pixel,
			&all->win.line_length, &all->win.endian);
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
}