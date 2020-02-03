/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:09:49 by ybenbrai          #+#    #+#             */
/*   Updated: 2020/02/03 18:42:29 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include <mlx.h>


# define width 800
# define height 600
#define black 0x000000
#define white 0xffffff
#define max 30

// mlx structure
typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_core;
	int			bpp;
	int			size_l;
	int			endian;
	
}				t_mlx;

//mandelbrot structure
typedef struct	s_mandel
{
	int			row;
	int			col;
	double		c_re;
	double		right_left;
	double		zoom_in;
	double		c_im;
	double		up_down;
	int			iteration;
	double		x;
	double		y;
	double		x_new;
	int			quality;
	int			hexa;
	int			octa;

	
}				t_mandel;

//the core structure
typedef struct	s_core
{

	t_mlx		mlx;
	t_mandel	mandel;
}				t_core;


void		mandelbrot(t_core *core);
int			keypress(int key, void *param);
int			mouse_press(int button, int x, int y, void *param);
#endif