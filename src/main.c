/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:43:27 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/26 16:04:00 by adjouber         ###   ########.fr       */
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

int		main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		ft_putendl("usage : ./fractol input_file");
		return (0);
	}
	t_fractol	fractol;
	if (!(fractol.mlx = mlx_init()))
	{
		ft_putendl("manque de place pour mlx_init");
		exit(0);
	}
	fractol.win = mlx_new_window(fractol.mlx, LON, HAU, "Fract'ol");
	mlx_hook(fractol.win, 2, 1L << 1, keyboard, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
