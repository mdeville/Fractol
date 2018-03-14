/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:51:21 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/14 15:34:05 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_graphics.h"

int		print_x(void *param)
{
	t_conf *conf;

	conf = get_conf();
	if (conf->mode == 1)
		iterate(param, conf, mandelbrot);
	else if (conf->mode == 2)
		iterate(param, conf, julia);
	conf->maxit += 1;
	return (1);
}
