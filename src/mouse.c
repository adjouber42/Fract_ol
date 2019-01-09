/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:58:19 by adjouber          #+#    #+#             */
/*   Updated: 2019/01/09 14:15:55 by adjouber         ###   ########.fr       */
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

int		mouse_click_hook(int k, int x, int y, t_fractol *f)
{
	if (k == MOUSE_ZOOM_IN)
	{
		f->x += x / 5;
		f->y += y / 5;
		f->z = f->z * 1.2;
		f->y = f->y * 1.2;
		f->x = f->x * 1.2;
	}
	if (k == MOUSE_ZOOM_OUT)
	{
		f->x -= x / 5;
		f->y -= y / 5;
		f->z = f->z / 1.2;
		f->y = f->y / 1.2;
		f->x = f->x / 1.2;
	}
	f->fractal(f);
	return (0);
}
