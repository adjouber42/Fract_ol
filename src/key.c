/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:22:05 by adjouber          #+#    #+#             */
/*   Updated: 2019/01/07 15:51:56 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	key_move(int key, t_fractol *f)
{
	if (key == KEY_DOWN)
		f->y += 10;
	if (key == KEY_UP)
		f->y -= 10;
	if (key == KEY_RIGHT)
		f->x += 10;
	if (key == KEY_LEFT)
		f->x -= 10;
}

static void	key_zoom(int key, t_fractol *f)
{
	if (key == KEY_ZOOM_IN)
	{
		f->x += LON / 12;
		f->y += HAU / 12;
		f->z = f->z * 1.2;
		f->x = f->x * 1.2;
		f->y = f->y * 1.2;
	}
	if (key == KEY_ZOOM_OUT)
	{
		if (f->z / 1.2 < 10 && key == KEY_ZOOM_OUT)
			return ;
		f->x -= LON / 12;
		f->y -= HAU / 12;
		f->z = f->z / 1.2;
		f->x = f->x / 1.2;
		f->y = f->y / 1.2;
	}
}

int			keyboard(int key, t_fractol *f)
{
	if (key == ESC_KEY )
		exit(0);
	if (key == KEY_DOWN || key == KEY_UP || key == KEY_LEFT || key == KEY_RIGHT)
		key_move(key, f);
	if (key == KEY_ZOOM_IN || key == KEY_ZOOM_OUT)
		key_zoom(key, f);
	return (0);
}
