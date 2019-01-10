/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:58:03 by adjouber          #+#    #+#             */
/*   Updated: 2019/01/10 15:10:05 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_change_color(t_fractol *f)
{
	if (f->color_value == 255)
		f->color_value = 1;
	else
		f->color_value++;
}

int		ft_color(int a, t_fractol *f)
{
	int				c;
	unsigned char	r;
	unsigned char	v;
	unsigned char	b;

	if (a == f->i_max)
		return (f->color_max);
	r = (a * 5) * f->color_value;
	v = (255 - (a * 10)) * f->color_value;
	b = (255 - (a * 2)) * f->color_value;
	if (f->color_set == 1)
		c = (v << 8) + (r << 16) + b;
	if (f->color_set == 3)
		c = (b << 8) + (v << 16) + r;
	if (f->color_set == 2)
		c = (r << 8) + (b << 16) + v;
	return (c);
}
