/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:09:21 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/12/04 19:53:47 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	ft_mb_init(t_data *data)
// {
	
	
// }
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
				data->img_data[data->row * width + data->col] = (data->iteration << data->hexa) | (data->iteration << data->octa) | (data->iteration);
				
			}
        	else 
				data->img_data[data->row * width + data->col] = 0x000000;
    }
	
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

int	main(int c, char **v)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	data->quality = 100;
	data->hexa = 1;
	data->octa = 8;
	data->right_left = 2.0;
	data->zoom_in = 4.0;
	data->up_down = 2.0;
	
	if (!c && !v)
	{
		return (0);
	}
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "fractol");
	data->img_ptr = mlx_new_image(data->mlx_ptr, width, height);
	
	data->img_data = (int *)mlx_get_data_addr(data->img_ptr, &data->bpp, &data->size_l, &data->endian);
	mandelbrot(data);
	mlx_hook(data->win_ptr, 2, 0, keypress, data);
	mlx_hook(data->win_ptr, 4, 0, mouse_press, data);
	
	mlx_loop(data->mlx_ptr);
	// }
	// free(data);
	// return (0);
}

	// while (++count_h < WIN_HEIGHT)
	// {
	// 	count_w = -1;
	// 	while (++count_w < WIN_WIDTH)
	// 			data->img.img_data[count_h * WIN_WIDTH + count_w] = 0xff0000;
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
	// }