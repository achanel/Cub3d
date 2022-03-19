#include "cub3D.h"

void	add_img(char *texture, t_all *all, int index)
{
	t_txt	img;
	int		*w = 64;

	img = all->txt[index];
	img.img = mlx_xpm_file_to_image(all->win.mlx, texture, &img.w, &img.h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	all->txt[index] = img;
}

void	add_rgb(char *texture, t_all *all, char index)
{
	t_txt	img;
	t_point	p;

	p.y = 0;
	p.x = 0;
	img.img = mlx_new_image(all->win.mlx, 1, 1);
	img.h = 1;
	img.w = 1;
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	if (index == 'F')
		my_mlx_pixel_put(all->win, p, 0x340707);//chok
	else
		my_mlx_pixel_put(all->win, p, 0x00FFFF);//cian
	all->txt[index] = img;
}

void	make_txt(t_all *all)
{
	add_rgb(NULL, all, 'F'); //F
	add_rgb(NULL, all, 'C'); //C
	add_img("../txt/EastBluegreyL.xpm", all, 0); //EA
	add_img("../txt/WestWoodbrickL.xpm", all, 1); //WE
	add_img("../txt/NorthMetallic.xpm", all, 2); //NO
	add_img("../txt/SouthMultibrickL.xpm", all, 3); // SO
}

void	player_data(char c, t_all *all, int i, int j)
{
	if (c == 'S')
		all->plr.angle = 3 * M_PI_2;
	else if (c == 'N')
		all->plr.angle = M_PI_2;
	else if (c == 'E')
		all->plr.angle = 0;
	else if (c == 'W')
		all->plr.angle = M_PI;
	all->plr.y = j + 0.5;
	all->plr.x = i + 0.5;
}

int	is_player_char(char c)
{
	if (c == 'S' || c == 'N' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	make_plr(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (all->map[++j])
	{
		while (all->map[j][++i])
		{
			if (is_player_char(all->map[j][i]))
			{
				player_data(all->map[j][i], all, i, j);
				all->map[j][i] = '0';
				return ;
			}
		}
		i = -1;
	}
	all->plr.up = 0;
	all->plr.down = 0;
	all->plr.left = 0;
	all->plr.right = 0;
}

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

void	test_parser(char *av1, t_all *all)
{
	int		fd = open("./maps/map.cub", O_RDONLY);
	char	*line = NULL;
	t_list	*head = NULL;

	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	make_map(all, &head, ft_lstsize(head));
	make_txt(all);
	make_plr(all);
}