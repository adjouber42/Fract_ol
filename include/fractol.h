/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:58:16 by adjouber          #+#    #+#             */
/*   Updated: 2019/01/03 15:11:12 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# define LON 600
# define HAU 400

typedef struct	s_frac
{
	long double	x1;
	long double	x2;
	long double	y1;
	long double	y2;
	long double	zr;
	long double	zi;
	long double	cr;
	long double	ci;
	long double	tmp;
}				t_frac;

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		(*fractal)();
	intmax_t	x;
	intmax_t	y;
	intmax_t	z;
	int			i_max;
	int			color_max;
	int			color_value;
	void		*img;
	char		*pxl;
	int			bpp;
	int			s_line;
	int			endia;
	t_frac		*mdb;
	t_frac		*jul;
}				t_fractol;

t_fractol		*init_val(void);
void			error(int i);
void			burningship(t_fractol *f);
void			pixel_put_image(t_fractol *f, int x, int y, unsigned int c);
int				ft_color(int a, t_fractol *f);

#endif
