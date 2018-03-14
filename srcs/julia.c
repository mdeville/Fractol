/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:10:42 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/14 16:24:17 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fractol.h"
#include "ft_graphics.h"

static t_pixel	palette(int iteration, int maxit, t_2dvector point)
{
	t_pixel res;

	if (iteration == maxit)
		res.hex = 0X00000000;
	else if (point.y > 0)
		res.hex = 0X00000000;
	else
		res.hex = 0X00FFFFFF;
	/*
	if (iteration == maxit)
		res.hex = 0X00000000;
	else if (iteration % 2 == 0)
		res.hex = 0X00000000;
	else
		res.hex = 0X00FFFFFF;*/
	return (res);
}

static int		escape_time(t_2dvector *point, t_2dvector c, int maxit)
{
	int		i;
	double	xtemp;
	double	x;
	double	y;

	i = 0;
	x = point->x;
	y = point->y;
	while (x * x + y * y < 4 && i < maxit)
	{
		xtemp = x * x - y * y + c.x;
		y = 2 * x * y + c.y;
		x = xtemp;
		++i;
	}
	point->x = x;
	point->y = y;
	return (i);
}

void			*julia(void *args)
{
	t_pargs		*pargs;
	t_2dvector	pixel;
	t_2dvector	tmp;
	int			iteration;

	pargs = (t_pargs *)args;
	pixel.y = pargs->miny;
	while (pixel.y < pargs->maxy)
	{
		pixel.x = 0;
		while (pixel.x < pargs->img->width)
		{
			tmp.x = pixel.x * pargs->pixel.x + pargs->cmin.x;
			tmp.y = pixel.y * pargs->pixel.y + pargs->cmin.y;
			iteration = escape_time(&tmp, pargs->julia_c, pargs->maxit);
			put_pixel(pargs->img, pixel, palette(iteration, pargs->maxit, tmp));
			++pixel.x;
		}
		++pixel.y;
	}
	return (NULL);
}
