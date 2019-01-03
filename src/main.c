/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:43:27 by adjouber          #+#    #+#             */
/*   Updated: 2019/01/03 15:07:30 by adjouber         ###   ########.fr       */
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
		ft_putendl("Error malloc");
}

void		julia(t_fractol *f)
{
	f->i_max = 1;
	ft_putendl("julia");
}

void		mandelbrot(t_fractol *f)
{
	f->i_max = 1;
	ft_putendl("mandelbrot");
}

int			main(int ac, char **av)
{
	t_fractol	*f;

	f = init_val();
	if (ac != 2)
		error(0);
	if (ft_strcmp(av[1], "julia") == 0)
		f->fractal = julia;	
	else if (ft_strcmp(av[1], "mandelbrot") == 0)
		f->fractal = mandelbrot;	
	else if (ft_strcmp(av[1], "burningship") == 0)
		f->fractal = burningship;	
	else
		error(0);
	if (!(f->mlx = mlx_init()))
	{
		ft_putendl("manque de place pour mlx_init");
		exit(0);
	}
	f->win = mlx_new_window(f->mlx, LON, HAU, "Fract'ol");
	mlx_hook(f->win, 2, 1L << 1, keyboard, f);
	f->fractal(f);
	mlx_loop(f->mlx);
	return (0);
}
