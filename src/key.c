/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:22:05 by adjouber          #+#    #+#             */
/*   Updated: 2019/01/17 14:08:13 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	key_move(int key, t_fractol *f)
{
	if (key == KEY_DOWN)
		f->y += 100;
	if (key == KEY_UP)
		f->y -= 100;
	if (key == KEY_RIGHT)
		f->x += 100;
	if (key == KEY_LEFT)
		f->x -= 100;
}

static void	key_zoom(int key, t_fractol *f)
{
	if (key == KEY_ZOOM_IN_1 || key == KEY_ZOOM_IN_2)
	{
		if (f->z * 1.2 > 1500000000 &&
				(key == KEY_ZOOM_IN_1 || key == KEY_ZOOM_IN_2))
			return ;
		f->x += f->width / 12;
		f->y += f->height / 12;
		f->z = f->z * 1.2;
		f->x = f->x * 1.2;
		f->y = f->y * 1.2;
		f->i_max += 3;
	}
	if (key == KEY_ZOOM_OUT_1 || key == KEY_ZOOM_OUT_2)
	{
		if (f->z / 1.2 < 10 && (key == KEY_ZOOM_OUT_1 || key == KEY_ZOOM_OUT_2))
			return ;
		f->x -= f->width / 12;
		f->y -= f->height / 12;
		f->z = f->z / 1.2;
		f->x = f->x / 1.2;
		f->y = f->y / 1.2;
		f->i_max -= 3;
	}
}

void		key_reset(int key, t_fractol *f)
{
	if (key == KEY_RESET)
	{
		f->x = 0;
		f->y = 0;
		f->z = 150;
		f->option_x = LON / 2;
		f->option_y = HAU / 2;
		f->color_max = 0x000000;
		f->i_max = 50;
		f->color_value = 1;
		f->mouse_stop = 0;
		f->color_change = 0;
		f->color_set = 1;
		f->zoom_auto = 0;
	}
}

void		key_color(int key, t_fractol *f)
{
	if (key == KEY_CYAN && f->color_set != 1)
		f->color_set = 1;
	if (key == KEY_JAUNE && f->color_set != 2)
		f->color_set = 2;
	if (key == KEY_MAGENTA && f->color_set != 3)
		f->color_set = 3;
}

int			keyboard(int key, t_fractol *f)
{
	key_zoom(key, f);
	key_move(key, f);
	key_reset(key, f);
	key_color(key, f);
	key_depth(key, f);
	if (key == ESC_KEY)
	{
		if (f->i < f->ac - 2)
		{
			f->i++;
			key_reset(KEY_RESET, f);
			frac(f);
		}
		else
			exit(0);
	}
	if (key == ZOOM_AUTO)
		f->zoom_auto = !f->zoom_auto;
	if (key == KEY_COLOR)
		f->color_change = !f->color_change;
	if (key == KEY_MOUSE_STOP)
		f->mouse_stop = !f->mouse_stop;
	f->fractal(f);
	return (0);
}
