/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 13:35:40 by elopukh           #+#    #+#             */
/*   Updated: 2018/07/01 13:35:41 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	initdata(t_window *win)
{
	win->size_line = W_WIN;
	win->bpp = 32;
	win->endian = 0;
	win->movex = 0;
	win->movey = 0;
	win->colour = 265;
	win->zoom = 1;
	win->img =
	mlx_get_data_addr(win->img_ptr, &win->bpp, &win->size_line, &win->endian);
}

void	init_2(t_window *win, t_window *win2)
{
	win->mlx_ptr = mlx_init();
	win2->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, H_WIN, W_WIN, "Window 1!");
	win->img_ptr = mlx_new_image(win->mlx_ptr, H_WIN, W_WIN);
	win2->win_ptr =
		mlx_new_window(win->mlx_ptr, H_WIN, W_WIN, "Window 2!");
	win2->img_ptr =
		mlx_new_image(win->mlx_ptr, H_WIN, W_WIN);
	initdata(win);
	initdata(win2);
	win->img =
	mlx_get_data_addr(win->img_ptr, &win->bpp, &win->size_line, &win->endian);
	win2->img =
	mlx_get_data_addr(win2->img_ptr, &win2->bpp, &win2->size_line,
		&win2->endian);
}

void	loop(t_window *win)
{
	mlx_mouse_hook(win->win_ptr, mousehandler, win);
	mlx_hook(win->win_ptr, 2, 1L << 0, key_handler, win);
	if (win->fract == 'j' || win->fract == 'c' || win->fract == 'f')
		mlx_hook(win->win_ptr, 6, 0, for_julia, win);
	mlx_loop(win->mlx_ptr);
}

void	loop2(t_window *win, t_window *win2)
{
	mlx_mouse_hook(win->win_ptr, mousehandler, win);
	mlx_hook(win->win_ptr, 2, 1L << 0, key_handler, win);
	mlx_mouse_hook(win2->win_ptr, mousehandler, win2);
	mlx_hook(win2->win_ptr, 2, 1L << 0, key_handler, win2);
	if (win->fract == 'j' || win->fract == 'c' || win->fract == 'f')
		mlx_hook(win->win_ptr, 6, 0, for_julia, win);
	if (win2->fract == 'j' || win2->fract == 'c' || win2->fract == 'f')
		mlx_hook(win2->win_ptr, 6, 0, for_julia, win2);
	mlx_loop(win->mlx_ptr);
}
