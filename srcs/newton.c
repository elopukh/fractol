/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 16:51:58 by elopukh           #+#    #+#             */
/*   Updated: 2018/06/28 16:52:00 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	iter_n(t_window *win)
{
	double old_re;
	double old_im;
	double p;

	old_re = win->rez;
	old_im = win->imz;
	p = pow((pow(old_re, 2) + pow(old_im, 2)), 2);
	win->rez = 2 / 3 * old_re + (pow(old_re, 2) -
		pow(old_im, 2)) / (3 * p * 1 / win->zoom);
	win->imz = 2 / 3 * old_im * (1 - old_re / p * 1 / win->zoom);
	win->red = fabs(old_re - win->rez);
	win->imd = fabs(old_im - win->imz);
}

void	count_n(double min, t_window *win, int maxiter)
{
	int i;

	win->rez = win->x * 0.005 + win->movex;
	win->imz = win->y * 0.005 + win->movey;
	win->red = win->rez;
	win->imd = win->imz;
	i = 0;
	while (i < maxiter && (pow(win->rez, 2) + pow(win->imz, 2) < 100000)
		&& (pow(win->red, 2) + pow(win->imd, 2) > min))
	{
		iter_n(win);
		i++;
	}
	pixel_put_img(win, win->x + W_WIN / 2, win->y + H_WIN / 2, win->colour * i);
}

void	newton(void *par)
{
	int			maxiter;
	double		min;
	t_window	*win;

	maxiter = 10;
	min = 0.000001;
	win = (t_window *)par;
	win->x = -W_WIN / 2;
	while (win->x < W_WIN / 2)
	{
		win->y = -H_WIN / 2;
		while (win->y < H_WIN / 2)
		{
			count_n(min, win, maxiter);
			win->y++;
		}
		win->x++;
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
}
