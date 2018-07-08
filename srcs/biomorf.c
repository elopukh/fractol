/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biomorf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 17:44:27 by elopukh           #+#    #+#             */
/*   Updated: 2018/06/28 17:44:28 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	put_b(t_window *win)
{
	if (win->new_re < 50 || win->new_im < 50 * 50)
	{
		win->colour = rand() % 68736236 + 1;
		pixel_put_img(win, win->x + W_WIN / 2, win->y + H_WIN / 2, win->colour);
	}
	else
		pixel_put_img(win, win->x + W_WIN / 2, win->y + H_WIN / 2, 0x00000);
}

void	count_b(double cre, double cim, t_window *win)
{
	int	i;

	win->new_re = fabs(win->x * 0.007 + win->movex);
	win->new_im = fabs(win->y * 0.007 + win->movey);
	i = -1;
	while ((win->new_re < 80 || win->new_im < 80 || sqrt(pow(win->new_re, 2)
	+ pow(win->new_im, 2)) < 80) && ++i < 50)
	{
		win->old_re = win->new_re;
		win->old_im = win->new_im;
		win->new_re = pow(win->old_re, 3) - 3 * win->old_im * win->old_im + cre;
		win->new_im = 3 * win->old_re * win->old_re *
			win->old_im - pow(win->old_im, 3) + cim;
		win->new_re = fabs(win->new_re) * win->zoom;
		win->new_im = fabs(win->new_im) * win->zoom;
	}
	put_b(win);
}

void	biomorf(t_window *win)
{
	double cre;
	double cim;

	cim = 0.0001;
	cre = -0.7;
	win->y = -H_WIN / 2;
	while (win->y < H_WIN / 2)
	{
		win->x = -W_WIN / 2;
		while (win->x < W_WIN / 2)
		{
			count_b(cre, cim, win);
			win->x++;
		}
		win->y++;
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
}
