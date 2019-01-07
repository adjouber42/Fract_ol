/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:43:27 by adjouber          #+#    #+#             */
/*   Updated: 2019/01/07 13:38:47 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		keyboard(int key, t_fractol *fractol)
{
	(void)fractol;
	if (key == 53)
		exit(0);
	return (0);
}

void	error(int i)
{
	if (i == 0)
	{
		ft_putendl("usage : ./fractol [julia/mandelbrot/burningship]");
		exit(1);
	}
	if (i == 1)
	{
		ft_putendl("Error malloc");
		exit(1);
	}
}

void		start(t_fractol *f)
{
	if (f->fractal == 1)
		julia(f);
	if (f->fractal == 2)
		mandelbrot(f);
	if (f->fractal == 3)
		burningship(f);
}

int			main(int ac, char **av)
{
	t_fractol	*f;

	if (!(f = (t_fractol*)malloc(sizeof(t_fractol))))
		error(1);
	if (ac != 2)
		error(0);
	if (ft_strcmp(av[1], "julia") == 0)
		f->fractal = 1;	
	else if (ft_strcmp(av[1], "mandelbrot") == 0)
		f->fractal = 2;	
	else if (ft_strcmp(av[1], "burningship") == 0)
		f->fractal = 3;	
	else
		error(0);
	if (!(f->mlx = mlx_init()))
	{
		ft_putendl("manque de place pour mlx_init");
		exit(0);
	}
	init_val(f);
	f->win = mlx_new_window(f->mlx, LON, HAU, "Fract'ol");
	mlx_hook(f->win, 2, 1L << 1, keyboard, f);
	start(f);
	mlx_loop(f->mlx);
	return (0);
}
