/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorne.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:27:47 by adjouber          #+#    #+#             */
/*   Updated: 2019/01/31 13:45:46 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	tri_bis(t_fractol *f)
{
	int		i;

	i = -1;
	while (++i < f->i_max)
	{
		f->mdb->tmp = f->mdb->zr;
		f->mdb->zr = f->mdb->zr * f->mdb->zr - f->mdb->zi * f->mdb->zi +
			f->mdb->cr;
		f->mdb->zi = -2 * f->mdb->zi * f->mdb->tmp + f->mdb->ci;
		if (f->mdb->zr * f->mdb->zr + f->mdb->zi * f->mdb->zi >= 4)
			return (i);
	}
	return (i);
}

void		tricorne(t_fractol *f)
{
	long	x;
	long	y;

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
			pixel_put_image(f, x - f->x, y - f->y, ft_color(tri_bis(f), (f)));
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
