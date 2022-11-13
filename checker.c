/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:24:08 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/13 14:25:33 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void controls()
{
	ft_putendl("Fractols:\n1. mandelbrot\n2. julia\n3. burningship\n");
	ft_putendl("Controls:\n");
	ft_putendl("Move: Arrow Keys\nZoom: Page Up & Page Down");
	ft_putendl("Mouse Zoom: Scrool Wheel");
	ft_putendl("Iteration: Left Click & (+ -) Keys");
	ft_putendl("Zoom Reset: Space Bar\nJulia Activate: Right Click");
	ft_putendl("Color Change: Num Key 1-3\nHue Change: Num Key 4 & 5");
	exit(1);
}

void check_arg(char *str, t_core *core)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		core->fractol = 1;
	else if (ft_strcmp(str, "julia") == 0)
		core->fractol = 2;
	else if (ft_strcmp(str, "burningship") == 0)
		core->fractol = 3;
	else
	{
		ft_putendl_fd("usage: ./fractol [mandelbrot, julia, burningship]", 2);
		exit(1);
	}
}