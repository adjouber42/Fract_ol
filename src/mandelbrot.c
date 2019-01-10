/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:50:43 by adjouber          #+#    #+#             */
/*   Updated: 2019/01/10 15:47:36 by adjouber         ###   ########.fr       */
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
		if (f->mdb->zr * f->mdb->zr + f->mdb->zi * f->mdb->zi >= 4)
			return (i);
	}
	return (i);
}

void		mandelbrot(t_fractol *f)
{
	size_t	x;
	size_t	y;

	x = f->x - 1;
	while (++x < f->width + f->x)
	{
		y = f->y - 1;
		while (++y < f->height + f->y)
		{
			f->mdb->zr = 0;
			f->mdb->zi = 0;
			f->mdb->cr = (long double)x / f->z + f->mdb->x1;
			f->mdb->ci = (long double)y / f->z + f->mdb->y1;
			pixel_put_image(f, x - f->x, y - f->y, ft_color(mdb_bis(f), f));
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
