/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:58:03 by adjouber          #+#    #+#             */
/*   Updated: 2019/01/03 15:09:44 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_color(int a, t_fractol *f)
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
	c = (r << 16) + (v << 8) + b;
	return (c);
}
