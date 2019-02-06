/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:30:20 by adjouber          #+#    #+#             */
/*   Updated: 2019/02/06 16:05:09 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_thread(void *data)
{
	t_threads	*t;

	t = (t_threads*)data;
	t->f->fractal(t->f, t->idx);
	pthread_exit(NULL);
}

void	draw_fractal(t_fractol *f)
{
	pthread_t	tid[THREADS];
	t_threads	t[THREADS];
	int			idx;

	idx = -1;
	while (++idx < THREADS)
	{
		t[idx].f = f;
		t[idx].idx = idx;
		if ((pthread_create(&tid[idx], NULL, ft_thread, &t[idx])) == -1)
			return ;
	}
	idx = -1;
	while (++idx < THREADS)
	{
		if (pthread_join(tid[idx], NULL))
			return ;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
