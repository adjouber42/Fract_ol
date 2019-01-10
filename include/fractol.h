/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:58:16 by adjouber          #+#    #+#             */
/*   Updated: 2019/01/10 15:46:48 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include "mlx.h"
# include <math.h>

# define LON 400
# define HAU 400
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ZOOM_IN_1 24
# define KEY_ZOOM_IN_2 69
# define KEY_ZOOM_OUT_1 27
# define KEY_ZOOM_OUT_2 78
# define ESC_KEY 53
# define MOUSE_ZOOM_IN 5
# define MOUSE_ZOOM_OUT 4
# define ZOOM_AUTO 18
# define KEY_RESET 49
# define KEY_MOUSE_STOP 35
# define KEY_COLOR 19
# define KEY_CYAN 8
# define KEY_JAUNE 46
# define KEY_MAGENTA 38
# define KEY_MORE_DEPTH 47
# define KEY_LESS_DEPTH 43

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
	size_t		x;
	size_t		y;
	size_t		z;
	int			option_x;
	int			option_y;
	int			i_max;
	int			width;
	int			height;
	int			color_max;
	int			color_value;
	void		*img;
	char		*pxl;
	int			bpp;
	int			s_line;
	int			endia;
	int			mouse_stop;
	int			zoom_auto;
	int			color_change;
	int			color_set;
	t_frac		*mdb;
	t_frac		*jul;
}				t_fractol;

t_fractol		*init_val(void);
void			error(int i);
void			burningship(t_fractol *f);
void			mandelbrot(t_fractol *f);
void			julia(t_fractol *f);
void			pixel_put_image(t_fractol *f, int x, int y, unsigned int c);
int				ft_color(int a, t_fractol *f);
int				keyboard(int key, t_fractol *f);
int				expose_hook(t_fractol *f);
int				mouse_move_hook(int x, int y, t_fractol *f);
int				mouse_click_hook(int k, int x, int y, t_fractol *f);
int				loop_hook(t_fractol *f);
void			ft_change_color(t_fractol *f);
void			key_depth(int key, t_fractol *f);

#endif
