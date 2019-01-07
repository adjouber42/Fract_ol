/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:50:43 by adjouber          #+#    #+#             */
/*   Updated: 2019/01/07 13:56:35 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mdb_bis(t_fractol *f)
{
	int		i;

	i = -1;
	while (++i < f->i_max)
	{
		f->mdb->tmp = f->mdb->zr;
		f->mdb->zr = f->mdb->zr * f->mdb->zr - f->mdb->zi * f->mdb->zi +
			f->mdb->cr;
		f->mdb->zi = 2 * f->mdb->zi * f->mdb->tmp + f->mdb->ci;
		if (f->mdb->zr * f->mdb->zr + f->mdb->zi * f->mdb->zi >= 1000)
			return (i);
	}
	return (i);
}

void		mandelbrot(t_fractol *f)
{
	int	x;
	int	y;

	x = f->x - 1;
	while (++x < LON + f->x)
	{
		y = f->y - 1;
		while (++y < HAU + f->y)
		{
			f->mdb->cr = (long double)x / f->z + f->mdb->x1;
			f->mdb->ci = (long double)y / f->z + f->mdb->y1;
			pixel_put_image(f, x - f->x, y - f->y, ft_color(mdb_bis(f), f));
			f->mdb->zr = 0;
			f->mdb->zi = 0;
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
