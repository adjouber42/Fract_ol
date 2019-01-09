/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:26:48 by adjouber          #+#    #+#             */
/*   Updated: 2019/01/09 15:17:14 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put_image(t_fractol *f, int x,int y, unsigned int c)
{
	int	i;

	i = (x * 4) + (y * f->s_line);
	f->pxl[i] = c;
	f->pxl[++i] = c >> 8;
	f->pxl[++i] = c >> 16;
}

int		expose_hook(t_fractol *f)
{
	f->fractal(f);
	return (0);
}

int		loop_hook(t_fractol *f)
{
	if (f->zoom_auto == 1)
	{
		f->z = f->z * 1.10;
		f->x = f->x * 1.10;
		f->y = f->y * 1.10;
		f->x += f->width / 20;
		f->y += f->height / 20;
		f->i_max += 2;
		f->fractal(f);
	}
	return (0);
}
