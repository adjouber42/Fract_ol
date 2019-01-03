/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 13:42:00 by adjouber          #+#    #+#             */
/*   Updated: 2019/01/03 15:09:13 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static t_frac	*init_mdb(void)
{
	t_frac		*m;

	if (!(m = (t_frac*)malloc(sizeof(t_frac))))
		error(1);
	m->x1 = -2.1;
	m->x2 = 0.6;
	m->y1 = -1.2;
	m->y2 = 1.2;
	m->zr = 0;
	m->zi = 0;
	m->cr = 0;
	m->ci = 0;
	m->tmp = 0;
	return (m);
}

static t_frac	*init_jul(void)
{
	t_frac		*j;

	if (!(j = (t_frac*)malloc(sizeof(t_frac))))
		error(1);
	j->x1 = -2.1;
	j->x2 = 0.6;
	j->y1 = -1.2;
	j->y2 = 1.2;
	j->zr = 0;
	j->zi = 0;
	j->cr = 0;
	j->ci = 0;
	j->tmp = 0;
	return (j);
}

t_fractol		*init_val(void)
{
	t_fractol	*f;

	if (!(f = (t_fractol*)malloc(sizeof(t_fractol))))
		error(1);
	f->x = 0;
	f->y = 0;
	f->z = 150;
	f->i_max = 50;
	f->color_max = 0x000000;
	f->color_value = 1;
	f->img = mlx_new_image(f->mlx, LON, HAU);
	f->pxl = mlx_get_data_addr(f->img, &(f->bpp), &(f->s_line), &(f->endia));
	f->mdb = init_mdb();
	f->jul = init_jul();
	return (f);
}
