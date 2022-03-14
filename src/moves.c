#include "cub3D.h"

void	move_up(t_all *all)
{
	int x;
	int y;
    
	x = (int)(all->plr->x + all->plr->dir_x * MV_SPEED);
	y = (int)(all->plr->y);
	if (all->map[y][x] == 0)
		all->plr->x += all->plr->dir_x * MV_SPEED;
	x = (int)(all->plr->x);
	y = (int)(all->plr->y + all->plr->dir_y * MV_SPEED);
	if (all->map[y][x] == 0)
		all->plr->y += all->plr->dir_y * MV_SPEED;
}

void	move_down(t_all *all)
{
	int x;
	int y;

	x = (int)(all->plr->x - all->plr->dir_x * MV_SPEED);
	y = (int)(all->plr->y);
	if (all->map[y][x] == 0)
		all->plr->x -= all->plr->dir_x * MV_SPEED;
	x = (int)(all->plr->x);
	y = (int)(all->plr->y - all->plr->dir_y * MV_SPEED);
	if (all->map[y][x] == 0)
		all->plr->y -= all->plr->dir_y * MV_SPEED;
}

void	move_right(t_all *all)
{
	double old_dirx;
	double old_planex;

	old_dirx = all->plr->dir_x;
	old_planex = all->plr->plane_x;
	all->plr->dir_x = all->plr->dir_x * cos(-ROT_SPEED) -
	all->plr->dir_y * sin(-ROT_SPEED);
	all->plr->dir_y = old_dirx * sin(-ROT_SPEED) +
	all->plr->dir_y * cos(-ROT_SPEED);
	all->plr->plane_x = all->plr->plane_x * cos(-ROT_SPEED) - all->plr->plane_y * sin(-ROT_SPEED);
	all->plr->plane_y = old_planex * sin(-ROT_SPEED) + all->plr->plane_y * cos(-ROT_SPEED);
}

void	move_left(t_all *all)
{
	double old_dirx;
	double old_planex;

	old_dirx = all->plr->dir_x;
	old_planex = all->plr->plane_x;
	all->plr->dir_x = all->plr->dir_x * cos(ROT_SPEED) -
	all->plr->dir_y * sin(ROT_SPEED);
	all->plr->dir_y = old_dirx * sin(ROT_SPEED) +
	all->plr->dir_y * cos(ROT_SPEED);
	all->plr->plane_x = all->plr->plane_x * cos(ROT_SPEED) - all->plr->plane_y * sin(ROT_SPEED);
	all->plr->plane_y = old_planex * sin(ROT_SPEED) + all->plr->plane_y * cos(ROT_SPEED);
}