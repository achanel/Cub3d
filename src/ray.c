#include "cub3D.h"
<<<<<<< HEAD
=======

static void	draw_ray_x(t_all *all, t_draw draw)
{
	int cumul;
	int	i;
	t_point	px;

	i = 1;
	px.x = draw.xi;
	px.y = draw.yi;
	cumul = draw.dx / 2;
	while (i <= draw.dx)
	{
		px.x += draw.xinc;
		if ((cumul += draw.dy) >= draw.dx)
		{
			cumul -= draw.dx;
			px.y += draw.yinc;
		}
		fill_pixel(&all->win->addr, px, draw.color);
		i++;
	}
}

static void	draw_ray_y(t_all *all, t_draw draw)
{
	int cumul;
	int	i;
	t_point py;

	i = 1;
	py.x = draw.xi;
	py.y = draw.yi;
	cumul = draw.dy / 2;
	while (i <= (int)draw.dy)
	{
		py.y += draw.yinc;
		if ((cumul += draw.dx) >= draw.dy)
		{
			cumul -= draw.dy;
			py.x += draw.xinc;
		}
		fill_pixel(&all->win->addr, py, draw.color);
		i++;
	}
}

void		draw_ray(t_all *all, double xf, double yf, int color)
{
	t_draw	draw;
	int		decalx;
	t_point	dp;

	decalx = WIDTH - MINI_MAPW;
	// draw.xf = xf * (double)(MINI_MAPW / SQUARE_MAP_SIZE) + decalx;
	// draw.yf = yf * (double)(MINI_MAPH / SQUARE_MAP_SIZE);
	// draw.xi = all->plr->x * (double)(MINI_MAPW / SQUARE_MAP_SIZE) + decalx;
	// draw.yi = all->plr->y * (double)(MINI_MAPH / SQUARE_MAP_SIZE);
	draw.dx = draw.xf - draw.xi;
	draw.dy = draw.yf - draw.yi;
	draw.xinc = draw.dx > 0 ? 1 : -1;
	draw.yinc = draw.dy > 0 ? 1 : -1;
	draw.dx = abs(draw.dx);
	draw.dy = abs(draw.dy);
	draw.color = color;
	dp.x = draw.xi;
	dp.y = draw.yi;
	fill_pixel(&all->win->addr, dp, draw.color);
	if (draw.dx > draw.dy)
		draw_ray_x(all, draw);
	else
		draw_ray_y(all, draw);
}
>>>>>>> 5a7d78122034e1fa7b31cc18bd870bd12670d18f
