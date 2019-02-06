/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:41:31 by adjouber          #+#    #+#             */
/*   Updated: 2019/02/06 17:34:03 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	jul_bis(t_fractol *f, long x, long y)
{
	int			i;
	long double	zr;
	long double	zi;
	long double	tmp;

	i = -1;
	zr = (long double)x / f->z + f->jul->x1;
	zi = (long double)y / f->z + f->jul->y1;
	while (++i < f->i_max)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + 0.285 +
			(0.4 * (double)f->option_x / (double)f->width);
		zi = 2 * zi * tmp + 0.01 /
			(0.4 * (double)f->option_y / (double)f->height);
		if (zr * zr + zi * zi >= 4)
			return (i);
	}
	return (i);
}

void		julia_2(t_fractol *f, int i)
{
	long	x;
	long	y;
	int		s;

	s = (f->width / THREADS);
	x = (i * s + f->x) - 1;
	while (++x < s * (i + 1) + f->x)
	{
		y = f->y - 1;
		while (++y < f->height + f->y)
			pixel_put_image(f, x - f->x, y - f->y,
					ft_color(jul_bis(f, x, y), f));
	}
}
