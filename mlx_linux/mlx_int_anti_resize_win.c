/*
** mlx_int_anti_resize_win.c for MiniLibX in
**
** Made by Charlie Root
** Login   <ol@epitech.net>
**
** Started on  Tue Aug  8 14:31:05 2000 Charlie Root
** Last update Tue Sep 25 15:56:58 2001 Charlie Root
*/

#include	"mlx_int.h"

void	init_everything(XSizeHints *hints);

int	mlx_int_anti_resize_win(t_xvar *xvar, Window win, int w, int h)
{
	XSizeHints	hints;
	long		toto;

	toto = 0;
	init_everything(&hints);
	XGetWMNormalHints(xvar->display, win, &hints, &toto);
	hints.width = w;
	hints.height = h;
	hints.min_width = w;
	hints.min_height = h;
	hints.max_width = w;
	hints.max_height = h;
	hints.flags = PPosition | PSize | PMinSize | PMaxSize;
	XSetWMNormalHints(xvar->display, win, &hints);
}

void	init_everything(XSizeHints *hints)
{
	hints->flags = 0;
	hints->x = 0;
	hints->y = 0;
	hints->width = 0;
	hints->height = 0;
	hints->min_width = 0;
	hints->min_height = 0;
	hints->max_width = 0;
	hints->max_height = 0;
	hints->width_inc = 0;
	hints->height_inc = 0;
	hints->min_aspect.x = 0;
	hints->min_aspect.y = 0;
	hints->max_aspect.x = 0;
	hints->max_aspect.y = 0;
	hints->base_width = 0;
	hints->base_height = 0;
	hints->win_gravity = 0;
}
