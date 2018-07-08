/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 17:57:28 by elopukh           #+#    #+#             */
/*   Updated: 2018/06/30 17:57:29 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	iter_a(double pr, double pi, t_window *win, int maxiter)
{
	double	new_re;
	double	new_im;
	double	old_re;
	double	old_im;
	int		i;

	pr = 1.5 * (win->x - W_WIN / 2) / (0.5 * win->zoom * W_WIN) + win->movex;
	pi = 1.5 * (win->y - H_WIN / 2) / (0.5 * win->zoom * H_WIN) + win->movey;
	new_re = 0;
	new_im = 0;
	old_re = 0;
	old_im = 0;
	i = 0;
	while (i < maxiter && (new_re * new_re + new_im * new_im) < 4)
	{
		old_re = new_re;
		old_im = new_im;
		new_re = old_re * old_re - old_im * old_im + pr;
		new_im = -2 * old_re * old_im + pi;
		i++;
	}
	if (i == maxiter)
		pixel_put_img(win, win->x, win->y, 0xFFFFFF);
	else
		pixel_put_img(win, win->x, win->y, win->colour * i);
}

void	*arrows(void *p)
{
	t_window	*win;
	double		pr;
	double		pi;
	double		tmp;
	double		maxiter;

	win = (t_window *)p;
	pr = 0;
	pi = 0;
	maxiter = 250;
	win->x = 0;
	tmp = win->y;
	while (win->x < W_WIN)
	{
		win->y = tmp;
		while (win->y < win->y_max)
		{
			iter_a(pr, pi, win, maxiter);
			win->y++;
		}
		win->x++;
	}
	return (p);
}

void	count_arrows(t_window *win)
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
		pthread_create(&t[i - 1], NULL, arrows, &tab[i - 1]);
	while (i--)
	{
		pthread_join(t[i], NULL);
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
}
