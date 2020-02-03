/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrotTools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:49:23 by ybenbrai          #+#    #+#             */
/*   Updated: 2020/02/03 18:52:24 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// function to initialise the structure variables of mandelbrot function
void	mandelInit(t_core *core)
{
	core->mandel.quality = 100;
	core->mandel.hexa = 1;
	core->mandel.octa = 8;
	core->mandel.right_left = 2.0;
	core->mandel.zoom_in = 4.0;
	core->mandel.up_down = 2.0;
}