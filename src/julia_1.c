/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:41:20 by adjouber          #+#    #+#             */
/*   Updated: 2019/01/17 15:41:22 by adjouber         ###   ########.fr       */
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

static void	*pixel_choice (void *data)
{
	long	x;
	long	y;
	long	part;
	long	start;
	t_thread	*t;

	t = (t_thread*)data;
	part = t->f->width / THREADS;
	start = part * get_thread(pthread_self(), (pthread_t*)t->thread);
	x = start - 1;
	while (++x < part * (t->idx + 1) + start)
	{
		y = t->f->y - 1;
		while (++y < t->f->height + t->f->y)
		{
			t->f->jul->zr = (long double)x / t->f->z + t->f->jul->x1;
			t->f->jul->zi = (long double)y / t->f->z + t->f->jul->y1;
			pixel_put_image(t->f, x - t->f->x, y - t->f->y, ft_color(jul_bis(t->f), t->f));
		}
	}
	pthread_exit(NULL);
}

void		julia_1(t_fractol *f)
{
	int	idx;
	t_thread	**t;

	if (!(t = (t_thread**)malloc(sizeof(t_thread*) * 8)))
		error(1);
	idx = -1;
	while (++idx < THREADS)
	{
		if (!(t[idx] = (t_thread*)malloc(sizeof(t_thread))))
			error(1);
		t[idx]->f = f;
		t[idx]->idx = idx;
		if ((pthread_create(&t[idx]->thread, NULL, pixel_choice, t[idx])) == -1)
			return ;
	}
	idx = -1;
	while (++idx < THREADS)
	{
		if (pthread_join(t[idx]->thread, NULL))
			return ;
		free(t[idx]);
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
