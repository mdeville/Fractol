/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:02:42 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/14 17:07:20 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <mlx.h>
#include "fractol.h"
#include "ft_graphics.h"

static t_pixel	palette(int iteration, int maxit, t_2dvector point)
{
	t_pixel res;

	(void)point;
	if (iteration == maxit)
		res.hex = 0X00000000;
	else
	{
		res.color.r = iteration * 0XFF / maxit;
		res.color.g = iteration * 0XFF / maxit;
		res.color.b = iteration * 0XFF / maxit;
	}
	/*
	if (iteration == maxit)
		res.hex = 0X00000000;
	else if (iteration % 2 == 0)
		res.hex = 0X00000000;
	else
		res.hex = 0X00FFFFFF;*/
	return (res);
}

static int		escape_time(t_2dvector *point, int maxit)
{
	int		i;
	double	x;
	double	y;
	double	xtemp;

	i = 0;
	x = 0.;
	y = 0.;
	while (x * x + y * y < 4 && i < maxit)
	{
		xtemp = x * x - y * y + point->x;
		y = 2 * x * y + point->y;
		x = xtemp;
		++i;
	}
	point->x = x;
	point->y = y;
	return (i);
}

void			*mandelbrot(void *args)
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
			iteration = escape_time(&tmp, pargs->maxit);
			put_pixel(pargs->img, pixel, palette(iteration, pargs->maxit, tmp));
			++pixel.x;
		}
		++pixel.y;
	}
	return (NULL);
}
