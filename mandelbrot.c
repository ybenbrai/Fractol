/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 22:38:40 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/11 17:54:07 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelInit(t_mandel *mandel)
{
	t_rgb **tex;
	
	tex  = 0;
	mandel->scale = 1./256;
	mandel->cx = -.6;
	mandel->cy = 0;
	mandel->color_rotate = 0;
	mandel->saturation = 1;
	mandel->invert = 0;
	mandel->max_iter = 256;
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
        	mandel->max_iter = 0;
        	while (mandel->x * mandel->x + mandel->y * mandel->y <= 4 && mandel->max_iter < mandel->quality)
			{
            	mandel->x_new = (mandel->x * mandel->x) - (mandel->y * mandel->y) + mandel->c_re;
            	mandel->y = (2 * mandel->x * mandel->y) + mandel->c_im;
            	mandel->x = mandel->x_new;
            	mandel->max_iter++;
        	}
			if (mandel->max_iter < mandel->quality)
			{
				mlx->img_core[mandel->row * WIDTH + mandel->col] = (mandel->max_iter << mandel->hexa) | (mandel->max_iter << mandel->octa) | (mandel->max_iter);

			}
        	else 
				mlx->img_core[mandel->row * WIDTH + mandel->col] = 0x033333;
    }

	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}