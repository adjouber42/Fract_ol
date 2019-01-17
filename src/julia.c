/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:16:27 by adjouber          #+#    #+#             */
/*   Updated: 2019/01/17 14:13:04 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	jul_bis(t_fractol *f)
{
	int		i;

	i = -1;
	while (++i < f->i_max)
	{
		f->jul->tmp = f->jul->zr;
		f->jul->zr = f->jul->zr * f->jul->zr - f->jul->zi * f->jul->zi - 0.8 +
			(0.6 / ((double)f->option_x / (double)f->width));
		f->jul->zi = 2 * f->jul->zi * f->jul->tmp + 0.27015 /
			((double)f->option_y / (double)f->height);
		if (f->jul->zr * f->jul->zr + f->jul->zi * f->jul->zi >= 4)
			return (i);
	}
	return (i);
}

void		julia(t_fractol *f)
{
	long	x;
	long	y;

	x = f->x - 1;
	while (++x < f->width + f->x)
	{
		y = f->y - 1;
		while (++y < f->height + f->y)
		{
			f->jul->zr = (long double)x / f->z + f->jul->x1;
			f->jul->zi = (long double)y / f->z + f->jul->y1;
			pixel_put_image(f, x - f->x, y - f->y, ft_color(jul_bis(f), f));
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
