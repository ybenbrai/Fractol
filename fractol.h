/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:09:49 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/11 18:46:11 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include "libft/libft.h"
#include <mlx.h>

// defining the width and heigh of the windows that display the image
#define WIDTH 800
#define HEIGHT 600

// defining some colors to make it possible to see with bare eyes
//  # define black 0x000000
//  # define white 0xffffff
//  # define max 30
typedef struct s_color
{
	unsigned char chan[3];
} t_c;

// the core structure
typedef struct s_core
{
	void *mlx;
	void *win;
	void *img;
	char *imgpointer;
	int bpp;
	int s1;
	int endian;
	int color;
	int fractol;
	double **map;
	double x;
	double y;
	double zoom;
	double movex;
	double movey;
	double cre;
	double cim;
	double oldre;
	double oldim;
	double newre;
	double newim;
	double pr;
	double pi;
	int maxinter;
	int i;
	double clickx;
	double clicky;
	double tmpx;
	double tmpy;
	int movemouse;
	double x2;
	double y2;
} t_core;

// core functions
// void mandelbrot(t_mandel *mandel, t_mlx *mlx);
//  void			mandelbrot(t_fractol *fractol);

// keyboard binding functions
int keypress(int key, void *param);

// mouse binding function
int mouse_press(int button, int x, int y, void *param);
#endif