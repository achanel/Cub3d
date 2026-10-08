/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:00:00 by achanel           #+#    #+#             */
/*   Updated: 2022/04/06 12:00:00 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	collect_sprites(t_all *all)
{
	int		i;
	float	dx;
	float	dy;

	i = -1;
	while (++i < all->sprite_count)
	{
		if (!all->sprites[i].alive)
			continue ;
		dx = all->sprites[i].x - all->plr.x;
		dy = all->sprites[i].y - all->plr.y;
		if (dx * dx + dy * dy < COLLECT_DIST * COLLECT_DIST)
			all->sprites[i].alive = 0;
	}
}

static void	sort_sprites(t_sprite *arr, float *dist, int n)
{
	int			i;
	int			j;
	t_sprite	tmp;
	float		td;

	i = -1;
	while (++i < n)
	{
		j = i;
		while (++j < n)
		{
			if (dist[j] > dist[i])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				td = dist[i];
				dist[i] = dist[j];
				dist[j] = td;
			}
		}
	}
}

static void	draw_sprite_column(t_all *all, int frame, t_sprite_view v)
{
	int				x;
	int				y;
	int				tex_x;
	int				tex_y;
	int				d;
	t_point			tex_p;
	t_point			draw_p;
	unsigned int	color;

	x = v.start_x - 1;
	while (++x <= v.end_x)
	{
		if (v.transform_y >= all->z_buffer[x])
			continue ;
		tex_x = (int)(256 * (x - (-v.w / 2 + v.screen_x))
				* all->txt[frame].w / v.w) / 256;
		if (tex_x < 0 || tex_x >= all->txt[frame].w)
			continue ;
		y = v.start_y - 1;
		while (++y <= v.end_y)
		{
			d = y * 256 - HEIGHT * 128 + v.h * 128;
			tex_y = ((d * all->txt[frame].h) / v.h) / 256;
			if (tex_y < 0 || tex_y >= all->txt[frame].h)
				continue ;
			tex_p.x = tex_x;
			tex_p.y = tex_y;
			color = get_texture_color(all->txt[frame], tex_p);
			if (color == all->sprite_transp)
				continue ;
			draw_p.x = x;
			draw_p.y = y;
			my_mlx_pixel_put(all->display, draw_p, color);
		}
	}
}

static void	draw_one_sprite(t_all *all, t_sprite *s, float dir_x,
				float dir_y, float plane_x, float plane_y, float inv_det)
{
	t_sprite_view	v;
	int				frame;
	float			sx;
	float			sy;

	sx = s->x - all->plr.x;
	sy = s->y - all->plr.y;
	v.transform_y = inv_det * (-plane_y * sx + plane_x * sy);
	if (v.transform_y <= 0.2f)
		return ;
	v.screen_x = (int)(WIDTH / 2 * (1 + (inv_det * (dir_y * sx - dir_x * sy))
				/ v.transform_y));
	frame = SPRITE0 + all->frame;
	if (!all->txt[frame].addr || all->txt[frame].w <= 0)
		return ;
	v.h = (int)fabsf(HEIGHT / v.transform_y);
	v.w = v.h;
	v.start_y = -v.h / 2 + HEIGHT / 2;
	if (v.start_y < 0)
		v.start_y = 0;
	v.end_y = v.h / 2 + HEIGHT / 2;
	if (v.end_y >= HEIGHT)
		v.end_y = HEIGHT - 1;
	v.start_x = -v.w / 2 + v.screen_x;
	if (v.start_x < 0)
		v.start_x = 0;
	v.end_x = v.w / 2 + v.screen_x;
	if (v.end_x >= WIDTH)
		v.end_x = WIDTH - 1;
	draw_sprite_column(all, frame, v);
}

void	draw_sprites(t_all *all)
{
	t_sprite	sorted[MAX_SPRITES];
	float		dist[MAX_SPRITES];
	int			n;
	int			i;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;

	n = 0;
	i = -1;
	while (++i < all->sprite_count)
	{
		if (!all->sprites[i].alive)
			continue ;
		dist[n] = (all->sprites[i].x - all->plr.x) * (all->sprites[i].x
				- all->plr.x) + (all->sprites[i].y - all->plr.y)
			* (all->sprites[i].y - all->plr.y);
		sorted[n] = all->sprites[i];
		n++;
	}
	dir_x = cos(all->plr.angle);
	dir_y = -sin(all->plr.angle);
	plane_x = 0.66 * sin(all->plr.angle);
	plane_y = 0.66 * cos(all->plr.angle);
	if (n > 1)
		sort_sprites(sorted, dist, n);
	i = -1;
	while (++i < n)
		draw_one_sprite(all, &sorted[i], dir_x, dir_y, plane_x, plane_y,
			1.0f / (plane_x * dir_y - dir_x * plane_y));
}
