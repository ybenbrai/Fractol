/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:09:49 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/12/04 19:52:27 by ybenbrai         ###   ########.fr       */
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


typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;

	void		*img_ptr;
	int			*img_data;
	int			size_l;
	int			bpp;
	int			endian;
	double			right_left;
	double			up_down;
	double			zoom_in;
	int row;
	int col;
	int hexa;
	int octa;
	double c_re;
	double test;
	double c_im;
	double x;
	double y;
	double x_new;
	int iteration;
	int quality;
}				t_data;

void	mandelbrot(t_data *data);
int    keypress(int key, void *param);
int     mouse_press(int button, int x, int y, void *param);
// void	ft_mb_init(t_data *data);
#endif