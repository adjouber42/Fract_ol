/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:58:19 by adjouber          #+#    #+#             */
/*   Updated: 2019/01/28 12:56:41 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move_hook(int x, int y, t_fractol *f)
{
	if (x < 0 || x >= f->width || y < 0 || y >= f->height ||
			f->mouse_stop == 1)
		return (0);
	f->option_x = x;
	f->option_y = y;
	f->fractal(f);
	return (0);
}

void	mouse_zoom(int k, int x, int y, t_fractol *f)
{
	if (k == MOUSE_ZOOM_IN)
	{
		f->x += x / 5;
		f->y += y / 5;
		f->z = f->z * 1.2;
		f->y = f->y * 1.2;
		f->x = f->x * 1.2;
		f->i_max += 2;
	}
	if (k == MOUSE_ZOOM_OUT)
	{
		if (f->z / 1.2 < 10 && k == MOUSE_ZOOM_OUT)
			return ;
		f->x -= x / 5;
		f->y -= y / 5;
		f->z = f->z / 1.2;
		f->y = f->y / 1.2;
		f->x = f->x / 1.2;
		f->i_max -= 2;
	}
}

int		mouse_translate(int x2, int y2, t_fractol *f)
{
	if (f->trans_stop == 0)
		return (0);
	f->x += (x2 - f->trans_x) / 4;
	f->y += (y2 - f->trans_y) / 4;
	f->fractal(f);
	return (0);
}

int		mouse_click_hook(int k, int x, int y, t_fractol *f)
{
	if (k == MOUSE_ZOOM_IN || k == MOUSE_ZOOM_OUT)
		mouse_zoom(k, x, y, f);
	if (k == MOUSE_CLICK)
	{
		f->trans_stop != 0 ? f->trans_stop = 0 : f->trans_stop++;
		f->trans_x = x;
		f->trans_y = y;
		mlx_hook(f->win, 6, (1L << 6), mouse_translate, f);
	}
	f->fractal(f);
	return (0);
}
