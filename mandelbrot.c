/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:48:40 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/13 14:49:42 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_mandelbrotInit(t_core *core)
{
	core->zoom = 1;
	core->movex = 0;
	core->movey = 0;
	core->maxinter = 15;
}

static void mandelassign(t_core *core)
{
	core->oldim = 0;
	core->oldre = core->oldim;
	core->newim = core->oldre;
	core->newre = core->newim;
}
static void mandelmagic(t_core *core)
{
	core->oldre = core->newre;
	core->oldim = core->newim;
	core->newre = core->oldre * core->oldre - core->oldim * core->oldim + core->pr;
	core->newim = 2 * core->oldre * core->oldim + core->pi;
}
void mandelfx(t_core *core)
{
	core->y = -1;
	while (++core->y < HEIGHT)
	{
		core->x = -1;
		while (++core->x < WIDTH)
		{
			core->pr = 1.5 * (core->x - WIDTH / 2) /
						   (0.5 * core->zoom * WIDTH) +
					   core->movex;
			core->pi = (core->y - HEIGHT / 2) /
						   (0.5 * core->zoom * HEIGHT) +
					   core->movey;
			mandelassign(core);
			core->i = -1;
			while (++core->i < core->maxinter)
			{
				mandelmagic(core);
				if ((core->newre * core->newre + core->newim * core->newim) > 4)
					break;
			}
			if (core->i < core->maxinter)
				putimage(core, core->x, core->y, (colormagic((core->color * core->i), core->x, core->y)));
			else
				putimage(core, core->x, core->y, 200);
		}
	}
}