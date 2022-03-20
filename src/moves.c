#include "cub3D.h"

void	move_up(t_all *all)
{
	float	y;
	float	x;

	printf("wwwww\n");
	y = all->plr.y;
	x = all->plr.x;
	if (sin(all->plr.angle * -1) < 0 && all->map[(int)(y - HITBOX)][(int)x] != '1')
		all->plr.y += sin(all->plr.angle * -1) * MV_SPEED;
	else if (sin(all->plr.angle * -1) > 0 && all->map[(int)(y + HITBOX)][(int)x] != '1')
		all->plr.y += sin(all->plr.angle * -1) * MV_SPEED;
	if (cos(all->plr.angle) > 0 && all->map[(int)y][(int)(x + HITBOX)] != '1')
		all->plr.x += cos(all->plr.angle) * MV_SPEED;
	else if (cos(all->plr.angle) < 0 && all->map[(int)y][(int)(x - HITBOX)] != '1')
		all->plr.x += cos(all->plr.angle) * MV_SPEED;
}

void	move_down(t_all *all)
{
	float	y;
	float	x;

	printf("ssss\n");
	y = all->plr.y;
	x = all->plr.x;
	if (sin(all->plr.angle) < 0 && all->map[(int)(y - HITBOX)][(int)x] != '1')
		all->plr.y += sin(all->plr.angle) * MV_SPEED;
	else if (sin(all->plr.angle) > 0 && all->map[(int)(y + HITBOX)][(int)x] != '1')
		all->plr.y += sin(all->plr.angle) * MV_SPEED;
	if (cos(all->plr.angle + M_PI) > 0 && all->map[(int)y][(int)(x + HITBOX)] != '1')
		all->plr.x += cos(all->plr.angle + M_PI) * MV_SPEED;
	else if (cos(all->plr.angle + M_PI) < 0 && all->map[(int)y][(int)(x - HITBOX)] != '1')
		all->plr.x += cos(all->plr.angle + M_PI) * MV_SPEED;
}

void	move_right(t_all *all)
{
	printf("ddd\n");
	all->plr.angle -= ROT_SPEED;
	if (all->plr.angle > 2 * M_PI)
		all->plr.angle -= 2 * M_PI;
	else if (all->plr.angle < 0)
		all->plr.angle += 2 * M_PI;
}

void	move_left(t_all *all)
{
	all->plr.angle += ROT_SPEED;
	if (all->plr.angle > 2 * M_PI)
		all->plr.angle -= 2 * M_PI;
	else if (all->plr.angle < 0)
		all->plr.angle += 2 * M_PI;
}