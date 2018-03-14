/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 13:20:09 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/14 23:35:20 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_graphics.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct	s_pargs
{
	t_image		*img;
	t_2dvector	pixel;
	t_2dvector	cmin;
	t_2dvector	julia_c;
	int			miny;
	int			maxy;
	int			maxit;
	double		(*calc)(t_2dvector *, t_2dvector, int maxit);
	t_pixel		(*palette)(double, int, t_2dvector);
}				t_pargs;

typedef struct	s_conf
{
	t_2dvector	min;
	t_2dvector	max;
	t_2dvector	julia_c;
	int			nbthread;
	int			maxit;
	double		hue;
	t_pixel		color;
	double		(*calc)(t_2dvector *, t_2dvector, int maxit);
	t_pixel		(*palette)(double, int, t_2dvector);
}				t_conf;

t_conf			*get_conf(void);
t_pixel			hsv_to_rgb(double h, double s, double v);
void			iterate(t_mlx *mlx, t_conf *conf);
int				mouse_press(int keycode, int x, int y, void *param);
int				mouse_hook(int x, int y, void *param);
int				key_hook(int keycode, void *param);
int				print_x(void *param);

/*
** Calc functions
*/

double			m_escape(t_2dvector *point, t_2dvector var, int maxit);
double			m_normalize(t_2dvector *point, t_2dvector var, int maxit);
double			j_escape(t_2dvector *point, t_2dvector c, int maxit);

/*
** Palette functions
*/

t_pixel			monochrome(double smooth, int maxit, t_2dvector point);
t_pixel			smooth(double smooth, int maxit, t_2dvector point);
t_pixel			zebra(double smooth, int maxit, t_2dvector point);

#endif
