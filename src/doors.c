/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:00:00 by achanel           #+#    #+#             */
/*   Updated: 2022/04/06 12:00:00 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_door	*find_door(t_all *all, int x, int y)
{
	int	i;

	i = -1;
	while (++i < all->door_count)
		if (all->doors[i].x == x && all->doors[i].y == y)
			return (&all->doors[i]);
	return (NULL);
}

int	is_solid(t_all *all, int x, int y)
{
	char	c;
	t_door	*door;

	if (y < 0 || !all->map[y] || x < 0
		|| x >= (int)ft_strlen(all->map[y]))
		return (1);
	c = all->map[y][x];
	if (c == '1')
		return (1);
	if (c == 'D')
	{
		door = find_door(all, x, y);
		return (!door || door->offset < 1.0f);
	}
	return (0);
}

void	build_entities(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	while (all->map[++i])
	{
		j = -1;
		while (all->map[i][++j])
		{
			if (all->map[i][j] == 'D' && all->door_count < MAX_DOORS)
			{
				all->doors[all->door_count].x = j;
				all->doors[all->door_count].y = i;
				all->doors[all->door_count].open = 0;
				all->doors[all->door_count].offset = 0.0f;
				all->door_count++;
			}
			else if (all->map[i][j] == '2'
				&& all->sprite_count < MAX_SPRITES)
			{
				all->sprites[all->sprite_count].x = j + 0.5f;
				all->sprites[all->sprite_count].y = i + 0.5f;
				all->sprites[all->sprite_count].alive = 1;
				all->sprite_count++;
				all->map[i][j] = '0';
			}
		}
	}
}

void	update_doors(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->door_count)
	{
		if (all->doors[i].open && all->doors[i].offset < 1.0f)
		{
			all->doors[i].offset += DOOR_SPEED;
			if (all->doors[i].offset > 1.0f)
				all->doors[i].offset = 1.0f;
		}
		else if (!all->doors[i].open && all->doors[i].offset > 0.0f)
		{
			all->doors[i].offset -= DOOR_SPEED;
			if (all->doors[i].offset < 0.0f)
				all->doors[i].offset = 0.0f;
		}
	}
}

void	toggle_door(t_all *all)
{
	int		i;
	int		best;
	float	dx;
	float	dy;
	float	dist;
	float	best_dist;

	i = -1;
	best = -1;
	best_dist = DOOR_OPEN_DIST * DOOR_OPEN_DIST;
	while (++i < all->door_count)
	{
		dx = all->doors[i].x + 0.5f - all->plr.x;
		dy = all->doors[i].y + 0.5f - all->plr.y;
		dist = dx * dx + dy * dy;
		if (dist <= best_dist)
		{
			best_dist = dist;
			best = i;
		}
	}
	if (best >= 0)
		all->doors[best].open = !all->doors[best].open;
}
