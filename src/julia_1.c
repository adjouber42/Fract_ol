/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:41:20 by adjouber          #+#    #+#             */
/*   Updated: 2019/01/28 17:20:45 by adjouber         ###   ########.fr       */
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
			return(i);
	}
	return(i);
}

static void	*pixel_choice(void *data)
{
	long		x;
	long		y;
	long		part;
	t_thread	*t;

	t = (t_thread*)data;
	part = t->f->width / 8;
	x = t->f->y - 1;
	while (x < part * (t->idx + 1) + t->f->x)
	{
		y = t->f->y - 1;
		while (y < t->f->height + t->f->y)
		{
			t->f->jul->zr = (long double)x / t->f->z + t->f->jul->x1;
			t->f->jul->zi = (long double)y / t->f->z + t->f->jul->y1;
			pixel_put_image(t->f, x - t->f->x, y - t->f->y, ft_color(jul_bis(t->f), t->f));
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void		julia_1(t_fractol *f)
{
	int			idx;
	t_thread	**threads;

	if (!(threads = (t_thread**)malloc(sizeof(t_thread*) * 8)))
		error(1);
	idx = -1;
	while (++idx < 8)
	{
		if (!(threads[idx] = (t_thread*)malloc(sizeof(t_thread))))
			error(1);
		threads[idx]->f = f;
		threads[idx]->idx = idx;
		if ((pthread_create(&threads[idx]->thread, NULL, pixel_choice, threads[idx])) == -1)
			return ;
	}
	idx = -1;
	while (++idx < 8)
	{
		if (pthread_join(threads[idx]->thread, NULL))
			return ;
		free(threads[idx]);
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
