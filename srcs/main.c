/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:10:50 by elopukh           #+#    #+#             */
/*   Updated: 2018/07/01 15:46:45 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		key_handler(int key, void *p)
{
	t_window *win;

	win = (t_window*)p;
	if (key == 53)
		exit(1);
	if (key == 69)
		win->zoom *= 1.1;
	if (key == 78)
		win->zoom *= 0.9;
	if (key == 8)
		win->colour += 1000;
	if (key >= 18 && key <= 28)
		change_fract(win, key);
	if (win->fract == 'j' || win->fract == 'c' || win->fract == 'w')
		mlx_hook(win->win_ptr, 6, 0, for_julia, win);
	sdvig(win, key);
	return (1);
}

int		mousehandler(int button, int x, int y, void *param)
{
	t_window *win;

	win = (t_window*)param;
	if (button == 5)
	{
		win->zoom *= 1.1;
		x = 0;
		y = 0;
	}
	if (button == 4)
	{
		win->zoom *= 0.9;
		x = 0;
		y = 0;
	}
	get_fractol(win);
	return (1);
}

int		main(int argc, char **argv)
{
	t_window *win;
	t_window *win2;

	if (argc == 2)
	{
		win = (t_window*)malloc(sizeof(t_window));
		init(win);
		if (check_fract(argv, win, 1) == 0)
			return (0);
		loop(win);
	}
	else if (argc == 3)
	{
		win = (t_window*)malloc(sizeof(t_window));
		win2 = (t_window*)malloc(sizeof(t_window));
		init_2(win, win2);
		if (check_fract(argv, win, 1) == 0 || check_fract(argv, win2, 2) == 0)
			return (0);
		loop2(win, win2);
	}
	else
		write(1, "I need only 1 or 2 arguments!\n", 30);
	return (0);
}
