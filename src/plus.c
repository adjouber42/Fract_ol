/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:26:48 by adjouber          #+#    #+#             */
/*   Updated: 2019/01/07 15:51:27 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put_image(t_fractol *f, int x,int y, unsigned int c)
{
	int	i;

	i = (x * 4) + (y * f->s_line);
	f->pxl[i] = c;
	f->pxl[++i] = c >> 8;
	f->pxl[++i] = c >> 16;
}

int		expose_hook(t_fractol *f)
{
	start(f);
	return (0);
}
