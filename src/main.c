/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:43:27 by adjouber          #+#    #+#             */
/*   Updated: 2019/02/04 15:05:22 by adjouber         ###   ########.fr       */
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
	ft_putendl("MOUSE STOP : p");
}

void	error(int i)
{
	if (i == 0)
	{
		ft_putendl("usage : ./fractol params (help)");
		exit(1);
	}
	if (i == 1)
	{
		ft_putendl("Error malloc");
		exit(1);
	}
	if (i == 2)
	{
		ft_putstr("params = mandelbrot, julia_1, julia_2,");
		ft_putendl(" julia_3, burningship, tricorne");
		exit(1);
	}
}

void	check(t_fractol *f)
{
	if (ft_strcmp(f->av, "help") == 0)
		error(2);
	else if (ft_strcmp(f->av, "julia_1") == 0)
		f->fractal = julia_1;
	else if (ft_strcmp(f->av, "julia_2") == 0)
		f->fractal = julia_2;
	else if (ft_strcmp(f->av, "julia_3") == 0)
		f->fractal = julia_3;
	else if (ft_strcmp(f->av, "julia_4") == 0)
		f->fractal = julia_4;
	else if (ft_strcmp(f->av, "mandelbrot") == 0)
		f->fractal = mandelbrot;
	else if (ft_strcmp(f->av, "tricorne") == 0)
		f->fractal = tricorne;
	else if (ft_strcmp(f->av, "burningship") == 0)
		f->fractal = burningship;
	else
			error(0);
}

void	frac(t_fractol *f)
{
	check(f);
	if (f->commande == 0)
	{
		commande();
		f->commande = 1;
	}
	mlx_key_hook(f->win, keyboard, f);
	mlx_hook(f->win, 6, 1L << 6, mouse_move_hook, f);
	mlx_mouse_hook(f->win, mouse_click_hook, f);
	mlx_loop_hook(f->mlx, loop_hook, f);
	f->fractal(f);
	mlx_loop(f->mlx);
}

int		main(int ac, char **av)
{
	t_fractol	*f;

	f = init_val();
	f->trans_stop = 0;
	if (ac < 2)
		error(0);
	f->commande = 0;
	f->av = ft_strdup(av[1]);
	f->win = mlx_new_window(f->mlx, f->width, f->height, "Fract'ol");
	frac(f);
	return (0);
}
