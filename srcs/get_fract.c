/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fract.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 13:27:19 by elopukh           #+#    #+#             */
/*   Updated: 2018/07/01 13:27:20 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	init(t_window *win)
{
	win->mlx_ptr = mlx_init();
	win->win_ptr =
	mlx_new_window(win->mlx_ptr, H_WIN, W_WIN, "This is fractol!");
	win->img_ptr = mlx_new_image(win->mlx_ptr, H_WIN, W_WIN);
	initdata(win);
	win->img =
	mlx_get_data_addr(win->img_ptr, &win->bpp, &win->size_line, &win->endian);
}

void	pixel_put_img(t_window *win, int x, int y, int colour)
{
	if (x < H_WIN || y < W_WIN)
	{
		colour = mlx_get_color_value(win->mlx_ptr, colour);
		ft_memcpy(win->img + 4 * W_WIN * y + x * 4, &colour, sizeof(int));
	}
}

void	get_fractol(t_window *win)
{
	if (win->fract == 'm')
		count_mandelbrot(win);
	if (win->fract == 'j')
		count_julia(win);
	if (win->fract == 'n')
		newton(win);
	if (win->fract == 'b')
		biomorf(win);
	if (win->fract == 's')
		count_ship(win);
	if (win->fract == 'c')
		count_cellule(win);
	if (win->fract == 'w')
		count_flower(win);
	if (win->fract == 'l')
		count_love(win);
	if (win->fract == 'a')
		count_arrows(win);
}

void	def_fract(char c, t_window *win)
{
	if (c == 'm')
		win->fract = c;
	if (c == 'j')
		win->fract = c;
	if (c == 'n')
		win->fract = c;
	if (c == 'b')
		win->fract = c;
	if (c == 's')
		win->fract = c;
	if (c == 'c')
		win->fract = c;
	if (c == 'w')
		win->fract = c;
	if (c == 'a')
		win->fract = c;
	if (c == 'l')
		win->fract = c;
	get_fractol(win);
}

int		check_fract(char **argv, t_window *win, int i)
{
	if (ft_strcmp(argv[i], "mandelbrot") == 0)
		def_fract('m', win);
	else if (ft_strcmp(argv[i], "julia") == 0)
		def_fract('j', win);
	else if (ft_strcmp(argv[i], "newton") == 0)
		def_fract('n', win);
	else if (ft_strcmp(argv[i], "biomorf") == 0)
		def_fract('b', win);
	else if (ft_strcmp(argv[i], "burning_ship") == 0)
		def_fract('s', win);
	else if (ft_strcmp(argv[i], "cellule") == 0)
		def_fract('c', win);
	else if (ft_strcmp(argv[i], "love") == 0)
		def_fract('l', win);
	else if (ft_strcmp(argv[1], "window") == 0)
		def_fract('w', win);
	else if (ft_strcmp(argv[i], "arrows") == 0)
		def_fract('a', win);
	else
	{
		usage();
		return (0);
	}
	return (1);
}
