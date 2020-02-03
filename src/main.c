/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:09:21 by ybenbrai          #+#    #+#             */
/*   Updated: 2020/02/03 18:24:53 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	return(0);
}