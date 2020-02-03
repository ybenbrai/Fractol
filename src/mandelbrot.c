/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 22:38:40 by ybenbrai          #+#    #+#             */
/*   Updated: 2020/02/03 18:33:42 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



void	mandelbrot(t_data *data)
{
	data->row = -1;
	while (++data->row < height)
	{
		data->col = -1;
		while(++data->col < width)
		{
			data->c_re  = (data->col - width / data->right_left) * data->zoom_in / width;
        	data->c_im  = (data->row - height / data->up_down) * data->zoom_in / width;
        	data->x = 0;
			data->y = 0;
        	data->iteration = 0;
        	while (data->x * data->x + data->y * data->y <= 4 && data->iteration < data->quality)
			{
            	data->x_new = (data->x * data->x) - (data->y * data->y) + data->c_re;
            	data->y = (2 * data->x * data->y) + data->c_im;
            	data->x = data->x_new;
            	data->iteration++;
        	}
			if (data->iteration < data->quality)
			{
				data->mlx.img_data[data->row * width + data->col] = (data->iteration << data->hexa) | (data->iteration << data->octa) | (data->iteration);

			}
        	else 
				data->mlx.img_data[data->row * width + data->col] = 0x000000;
    }

	}
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->mlx.img_ptr, 0, 0);
}