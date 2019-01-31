/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:11:59 by adjouber          #+#    #+#             */
/*   Updated: 2019/01/31 16:11:42 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	*thread_bis(void *data)
{
	t_thread	*t;

	t = (t_thread*)data;
	t->f->fractal(t->f, t->idx);
	pthread_exit(NULL);
}

void	draw_fractal(t_fractol *f)
{
	int			i;
	pthread_t	tid[THREADS];
	t_thread	t[THREADS];

	i = -1;
	while (++i < THREADS)
	{
		t[i].f = f;
		t[i].idx = i;
		if ((pthread_create(&tid[i], NULL, thread_bis, &t[i])) == -1)
			return ;
	}
	i = -1;
	while (++i < THREADS)
		if (pthread_join(tid[i], NULL))
			return ;
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

unsigned int	get_thread(pthread_t id, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < THREADS && !pthread_equal(id, threads[i]))
		i++;
	return (i);
}
