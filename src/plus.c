/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:26:48 by adjouber          #+#    #+#             */
/*   Updated: 2019/03/06 12:20:20 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put_image(t_fractol *f, int x, int y, unsigned int c)
{
	int	i;

	i = (x * 4) + (y * f->s_line);
	f->pxl[i] = c;
	f->pxl[++i] = c >> 8;
	f->pxl[++i] = c >> 16;
}

void	key_depth(int key, t_fractol *f)
{
	if (key == KEY_MORE_DEPTH)
		f->i_max += 10;
	if (key == KEY_LESS_DEPTH)
	{
		if (f->i_max - 10 <= 0)
			return ;
		f->i_max -= 10;
	}
}

int		loop_hook(t_fractol *f)
{
	if (f->color_change == 1)
	{
		ft_change_color(f);
		draw_fractal(f);
	}
	if (f->zoom_auto == 1)
	{
		f->z = f->z * 1.10;
		f->x = f->x * 1.10;
		f->y = f->y * 1.10;
		f->x += f->width / 20;
		f->y += f->height / 20;
		f->i_max += 2;
		draw_fractal(f);
	}
	return (0);
}

void	ft_free(t_fractol *f)
{
	free(f->av);
	free(f->mdb);
	free(f->jul);
	free(f);
}

int		close_prog(t_fractol *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	ft_free(f);
	exit(0);
	return (0);
}
