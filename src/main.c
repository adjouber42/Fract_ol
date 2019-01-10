/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:43:27 by adjouber          #+#    #+#             */
/*   Updated: 2019/01/10 15:56:29 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	commande(void)
{
	ft_putendl("MOVE : up down left right");
	ft_putendl("ZOOM : + -");
	ft_putendl("RESET : space");
	ft_putendl("ZOOM AUTO : 1");
	ft_putendl("COLOR PSYCHADELIC : 2");
	ft_putendl("CHANGE COLOR : c m j");
	ft_putendl("DEPTH : < >");
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

int		main(int ac, char **av)
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
	f->win = mlx_new_window(f->mlx, f->width, f->height, "Fract'ol");
	mlx_expose_hook(f->win, expose_hook, f);
	mlx_key_hook(f->win, keyboard, f);
	mlx_hook(f->win, 6, 1L << 6, mouse_move_hook, f);
	mlx_mouse_hook(f->win, mouse_click_hook, f);
	mlx_loop_hook(f->mlx, loop_hook, f);
	commande();
	f->fractal(f);
	mlx_loop(f->mlx);
	return (0);
}
