/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 13:32:36 by elopukh           #+#    #+#             */
/*   Updated: 2018/07/01 13:32:37 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	zooming(t_window *win)
{
	win->zoom += 2;
	get_fractol(win);
}

void	sdvig(t_window *win, int key)
{
	if (key == 125)
		win->movey += 0.3 / win->zoom;
	if (key == 126)
		win->movey -= 0.3 / win->zoom;
	if (key == 123)
		win->movex -= 0.3 / win->zoom;
	if (key == 124)
		win->movex += 0.3 / win->zoom;
	get_fractol(win);
}

int		for_julia(int x, int y, t_window *win)
{
	if (win->fract == 'j' || win->fract == 'c')
	{
		win->pos_x = 1.5 * (x - W_WIN / 2)
			/ (0.5 * win->zoom * W_WIN) + win->movex;
		win->pos_y = 1.5 * (y - H_WIN / 2)
			/ (0.5 * win->zoom * H_WIN) + win->movey;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		if (win->fract == 'j')
			count_julia(win);
		if (win->fract == 'c')
			count_cellule(win);
	}
	return (1);
}

void	change_fract(t_window *win, int key)
{
	win->zoom = 1;
	win->colour = 265;
	win->movex = 0;
	win->movey = 0;
	if (key == 18)
		def_fract('m', win);
	if (key == 19)
		def_fract('j', win);
	if (key == 20)
		def_fract('b', win);
	if (key == 21)
		def_fract('n', win);
	if (key == 22)
		def_fract('s', win);
	if (key == 23)
		def_fract('c', win);
	if (key == 26)
		def_fract('l', win);
	if (key == 28)
		def_fract('w', win);
	if (key == 25)
		def_fract('a', win);
}

void	usage(void)
{
	write(1, "USAGE: ./fractol [arg]\n", 23);
	write(1, "1.mandelbrot\n2.newton\n3.biomorf\n", 32);
	write(1, "4.burning_ship\n5.julia\n6.cellule\n", 34);
	write(1, "7.love\n8.window\n9.arrows\n", 25);
}
