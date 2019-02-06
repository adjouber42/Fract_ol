/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:50:43 by adjouber          #+#    #+#             */
/*   Updated: 2019/02/06 17:33:42 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mdb_bis(t_fractol *f, long double *c)
{
	int			i;
	long double	zr;
	long double	zi;
	long double	tmp;

	i = -1;
	zr = 0;
	zi = 0;
	while (++i < f->i_max)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + c[0];
		zi = 2 * zi * tmp + c[1];
		if (zr * zr + zi * zi >= 4)
			return (i);
	}
	return (i);
}

void		mandelbrot(t_fractol *f, int i)
{
	long		x;
	long		y;
	int			s;
	long double	c[2];

	s = (f->width / THREADS);
	x = (i * s + f->x) - 1;
	while (++x < s * (i + 1) + f->x)
	{
		y = f->y - 1;
		while (++y < f->height + f->y)
		{
			c[0] = (long double)x / f->z + f->mdb->x1;
			c[1] = (long double)y / f->z + f->mdb->y1;
			pixel_put_image(f, x - f->x, y - f->y,
					ft_color(mdb_bis(f, c), f));
		}
	}
}
