/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:51:39 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/13 14:52:08 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void putimage(t_core *core, int x, int y, int color)
{
	int i;

	i = (x * (core->bpp / 8)) + (y * core->s1);
	core->imgpointer[i] = color;
	core->imgpointer[++i] = color >> 8;
	core->imgpointer[++i] = color >> 16;
}

unsigned int colormagic(int i, double x, double y)
{
	unsigned int color;
	double magic;
	double i2;
	t_c c;

	magic = sqrt(x * x + y * y);
	i2 = i + 1 - (log(2) / magic) / log(2);
	c.chan[0] = (unsigned char)(sin(0.026 * i2 + 4) * 230 + 25);
	c.chan[1] = (unsigned char)(sin(0.023 * i2 + 2) * 230 + 25);
	c.chan[2] = (unsigned char)(sin(0.01 * i2 + 1) * 230 + 25);
	color = (c.chan[0] << 16) + (c.chan[1] << 8) + (c.chan[2] + 255);
	return (color);
}