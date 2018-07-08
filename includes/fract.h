/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 18:19:35 by elopukh           #+#    #+#             */
/*   Updated: 2018/06/02 18:19:38 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H
# include "./minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include "../libft/libft.h"

# define H_WIN 1000
# define W_WIN 1000

typedef double	t_dot3 __attribute__((vector_size(sizeof(double)*3)));
typedef double	t_dot2 __attribute__((vector_size(sizeof(double)*2)));

typedef struct
{
	int			height;
	int			width;
	double		pos_x;
	double		pos_y;
	double		x;
	double		y;
	int			colour;
	double		y_max;
	void		*mlx_ptr;
	void		*mlx_ptr2;
	void		*win_ptr;
	void		*win_ptr2;
	void		*img_ptr2;
	void		*img_ptr;
	int			size_line;
	int			bpp;
	double		rez;
	double		imz;
	double		red;
	double		imd;
	double		new_re;
	double		new_im;
	double		old_re;
	double		old_im;
	int			endian;
	char		*img;
	char		*img2;
	char		fract;
	char		fract2;
	double		movex;
	double		movey;
	double		zoom;
}				t_window;

void			*mandelbrot(void *p);
void			pixel_put_img(t_window *win, int x, int y, int colour);
void			*julia(void *p);
void			count_julia(t_window *win);
void			count_mandelbrot(t_window *win);
void			*burning_ship(void *p);
void			count_ship(t_window *win);
void			newton(void *win);
void			biomorf(t_window *win);
void			count_cellule(t_window *win);
void			count_love(t_window *win);
void			count_flower(t_window *win);
void			count_arrows(t_window *win);
void			get_fractol(t_window *win);
void			init(t_window *win);
int				check_fract(char **argv, t_window *win, int i);
void			def_fract(char c, t_window *win);
int				for_julia(int x, int y, t_window *win);
void			sdvig(t_window *win, int key);
int				for_julia(int x, int y, t_window *win);
void			init_2(t_window *win, t_window *win2);
void			loop(t_window *win);
void			loop2(t_window *win, t_window *win2);
void			change_fract(t_window *win, int key);
void			usage(void);
void			initdata(t_window *win);
int				key_handler(int key, void *p);
int				mousehandler(int button, int x, int y, void *param);
#endif
