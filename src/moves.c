/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:49:12 by achanel           #+#    #+#             */
/*   Updated: 2022/03/22 14:57:01 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	move(float pl_cos, float pl_sin, t_all *all)
{
	float	y;
	float	x;

	y = all->plr.y;
	x = all->plr.x;
	if (sin(pl_sin) < 0 && all->map[(int)(y - HITBOX)][(int)x] != '1')
		all->plr.y += sin(pl_sin) * MV_SPEED;
	else if (sin(pl_sin) > 0 && all->map[(int)(y + HITBOX)][(int)x] != '1')
		all->plr.y += sin(pl_sin) * MV_SPEED;
	if (cos(pl_cos) > 0 && all->map[(int)y][(int)(x + HITBOX)] != '1')
		all->plr.x += cos(pl_cos) * MV_SPEED;
	else if (cos(pl_cos) < 0 && all->map[(int)y][(int)(x - HITBOX)] != '1')
		all->plr.x += cos(pl_cos) * MV_SPEED;
}

static void	spin_right(t_all *all)
{
	all->plr.angle -= ROT_SPEED;
	if (all->plr.angle > 2 * M_PI)
		all->plr.angle -= 2 * M_PI;
	else if (all->plr.angle < 0)
		all->plr.angle += 2 * M_PI;
}

static void	spin_left(t_all *all)
{
	all->plr.angle += ROT_SPEED;
	if (all->plr.angle > 2 * M_PI)
		all->plr.angle -= 2 * M_PI;
	else if (all->plr.angle < 0)
		all->plr.angle += 2 * M_PI;
}

void	move_spin(t_all *all)
{
	if (all->plr.up)
		move(all->plr.angle, -all->plr.angle, all);
	if (all->plr.down)
		move(all->plr.angle + M_PI, all->plr.angle, all);
	if (all->plr.left)
		move(all->plr.angle + M_PI_2, all->plr.angle - M_PI_2, all);
	if (all->plr.right)
		move(all->plr.angle - M_PI_2, all->plr.angle + M_PI_2, all);
	if (all->plr.spin_l)
		spin_left(all);
	if (all->plr.spin_r)
		spin_right(all);
}
