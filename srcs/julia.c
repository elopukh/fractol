/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 13:40:16 by elopukh           #+#    #+#             */
/*   Updated: 2018/06/28 13:40:17 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	iter(double cre, double cim, t_window *win, int maxiter)
{
	double	new_re;
	double	new_im;
	double	old_re;
	double	old_im;
	int		i;

	new_re = 1.5 * (win->x - W_WIN / 2) /
	(0.5 * win->zoom * W_WIN) + win->movex;
	new_im = 1.3 * (win->y - H_WIN / 2) /
	(0.5 * win->zoom * H_WIN) + win->movey;
	i = 0;
	while (i < maxiter && (new_re * new_re + new_im * new_im) < 4)
	{
		old_re = new_re;
		old_im = new_im;
		new_re = old_re * old_re - old_im * old_im + (cre);
		new_im = 2 * old_re * old_im + (cim);
		i++;
	}
	if (i == maxiter)
		pixel_put_img(win, win->x, win->y, 0xFFFFFF);
	else
		pixel_put_img(win, win->x, win->y, win->colour * i);
}

void	*julia(void *p)
{
	t_window	*win;
	double		tmp;
	double		cre;
	double		cim;
	int			maxiter;

	win = (t_window *)p;
	cre = win->pos_x;
	cim = win->pos_y;
	win->x = 0;
	maxiter = 400;
	tmp = win->y;
	while (win->x < H_WIN)
	{
		win->y = tmp;
		while (win->y < win->y_max)
		{
			iter(cre, cim, win, maxiter);
			win->y++;
		}
		win->x++;
	}
	return (p);
}

void	count_julia(t_window *win)
{
	int			i;
	t_window	tab[20];
	pthread_t	t[20];

	i = 0;
	while (i < 20)
	{
		ft_memcpy((void *)&tab[i], (void *)win, sizeof(t_window));
		tab[i].y = 50 * i;
		tab[i].y_max = 50 * (i + 1);
		i++;
	}
	i = 0;
	while (++i <= 20)
		pthread_create(&t[i - 1], NULL, julia, &tab[i - 1]);
	while (i--)
	{
		pthread_join(t[i], NULL);
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
}
