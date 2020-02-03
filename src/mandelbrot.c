/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 22:38:40 by ybenbrai          #+#    #+#             */
/*   Updated: 2020/02/03 19:07:13 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



void	mandelbrot(t_core *core)
{
	core->mandel.row = -1;
	while (++core->mandel.row < height)
	{
		core->mandel.col = -1;
		while(++core->mandel.col < width )
		{
			core->mandel.c_re  = (core->mandel.col - width / core->mandel.right_left) * core->mandel.zoom_in / width;
        	core->mandel.c_im  = (core->mandel.row - height / core->mandel.up_down) * core->mandel.zoom_in / width;
        	core->mandel.x = 0;
			core->mandel.y = 0;
        	core->mandel.iteration = 0;
        	while (core->mandel.x * core->mandel.x + core->mandel.y * core->mandel.y <= 4 && core->mandel.iteration < core->mandel.quality)
			{
            	core->mandel.x_new = (core->mandel.x * core->mandel.x) - (core->mandel.y * core->mandel.y) + core->mandel.c_re;
            	core->mandel.y = (2 * core->mandel.x * core->mandel.y) + core->mandel.c_im;
            	core->mandel.x = core->mandel.x_new;
            	core->mandel.iteration++;
        	}
			if (core->mandel.iteration < core->mandel.quality)
			{
				core->mlx.img_core[core->mandel.row * width + core->mandel.col] = (core->mandel.iteration << core->mandel.hexa) | (core->mandel.iteration << core->mandel.octa) | (core->mandel.iteration);

			}
        	else 
				core->mlx.img_core[core->mandel.row * width + core->mandel.col] = 0x000000;
    }

	}
	mlx_put_image_to_window(core->mlx.mlx_ptr, core->mlx.win_ptr, core->mlx.img_ptr, 0, 0);
}