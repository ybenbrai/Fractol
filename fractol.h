/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:09:49 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/13 15:41:01 by ybenbrai         ###   ########.fr       */
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

#define WIDTH 700
#define HEIGHT 700

typedef struct s_color
{
	unsigned char chan[3];
} t_c;

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

void			controls();
void			check_arg(char *str, t_core *core);
void			ft_window(t_core *core);
void 			redrawing(t_core *core);
void			fractolsInit(t_core *core);
void 			fractolPicker(t_core *core);
void 			ft_mandelbrotInit(t_core *core);
void			mandelfx(t_core *core);
int				keysMap(int key, t_core *core);
int				colorsKeys(int key, t_core *core);
int				directionsKeys(int key, t_core *core);
int				moves(int x, int y, t_core *core);
int				mouseKeys(int mousekey, int x, int y, t_core *core);
void 			putimage(t_core *core, int x, int y, int color);
int				closing(t_core *core);
unsigned int	colormagic(int i, double x, double y);

#endif