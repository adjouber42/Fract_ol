/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:43:27 by adjouber          #+#    #+#             */
/*   Updated: 2019/01/17 14:35:18 by adjouber         ###   ########.fr       */
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
		ft_putendl("usage : ./fractol [julia/mandelbrot/burningship]");
		exit(1);
	}
	if (i == 1)
	{
		ft_putendl("Error malloc");
		exit(1);
	}
}

void	check(t_fractol *f)
{
	if (ft_strcmp(f->av[f->i], "julia") == 0)
		f->fractal = julia;
	else if (ft_strcmp(f->av[f->i], "mandelbrot") == 0)
		f->fractal = mandelbrot;
	else if (ft_strcmp(f->av[f->i], "burningship") == 0)
		f->fractal = burningship;
	else
	{
		if (f->i < f->ac - 2)
		{
			ft_putendl("usage : ./fractol [julia/mandelbrot/burningship]");
			f->i++;
			frac(f);
		}
		else
			error(0);
	}
}

void	frac(t_fractol *f)
{
	check(f);
	if (f->commande == 0)
	{
		commande();
		f->commande = 1;
	}
	mlx_expose_hook(f->win, expose_hook, f);
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
	int			k;

	k = 0;
	if (ac < 2)
		error(0);
	f = init_val();
	f->commande = 0;
	f->i = 0;
	f->ac = ac;
	if (!(f->av = (char**)malloc(sizeof(char*) * (ac + 1))))
		return (0);
	while (k + 1 < ac)
	{
		f->av[k] = ft_strdup(av[k + 1]);
		k++;
	}
	f->win = mlx_new_window(f->mlx, f->width, f->height, "Fract'ol");
	frac(f);
	return (0);
}
