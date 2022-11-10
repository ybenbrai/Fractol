/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 22:38:40 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/10 23:43:03 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelInit(t_mandel *mandel)
{
	mandel->quality = 100;
	mandel->hexa = 1;
	mandel->octa = 8;
	mandel->right_left = 2;
	mandel->zoom_in = 4;
	mandel->up_down = 2;
}

void	mandelbrot(t_mandel *mandel,t_mlx *mlx)
{
	mandel->row = -1;
	while (++mandel->row < HEIGHT)
	{
		mandel->col = -1;
		while(++mandel->col < WIDTH )
		{
			mandel->c_re  = (mandel->col - WIDTH / mandel->right_left) * mandel->zoom_in / WIDTH;
        	mandel->c_im  = (mandel->row - HEIGHT / mandel->up_down) * mandel->zoom_in / WIDTH;
        	mandel->x = 0;
			mandel->y = 0;
        	mandel->iteration = 0;
        	while (mandel->x * mandel->x + mandel->y * mandel->y <= 4 && mandel->iteration < mandel->quality)
			{
            	mandel->x_new = (mandel->x * mandel->x) - (mandel->y * mandel->y) + mandel->c_re;
            	mandel->y = (2 * mandel->x * mandel->y) + mandel->c_im;
            	mandel->x = mandel->x_new;
            	mandel->iteration++;
        	}
			if (mandel->iteration < mandel->quality)
			{
				mlx->img_core[mandel->row * WIDTH + mandel->col] = (mandel->iteration << mandel->hexa) | (mandel->iteration << mandel->octa) | (mandel->iteration);

			}
        	else 
				mlx->img_core[mandel->row * WIDTH + mandel->col] = 0x000000;
    }

	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}