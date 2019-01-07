/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:58:16 by adjouber          #+#    #+#             */
/*   Updated: 2019/01/07 15:52:33 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# define LON 600
# define HAU 400

# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ZOOM_IN 24
# define KEY_ZOOM_OUT 27
# define ESC_KEY 53

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
	int			fractal;
	intmax_t	x;
	intmax_t	y;
	intmax_t	z;
	int			option_x;
	int			option_y;
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

void			init_val(t_fractol *f);
void			error(int i);
void			burningship(t_fractol *f);
void			mandelbrot(t_fractol *f);
void			julia(t_fractol *f);
void			pixel_put_image(t_fractol *f, int x, int y, unsigned int c);
int				ft_color(int a, t_fractol *f);
int				keyboard(int key, t_fractol *f);
void			start(t_fractol *f);
int				expose_hook(t_fractol *f);

#endif
