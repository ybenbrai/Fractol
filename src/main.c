/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:09:21 by ybenbrai          #+#    #+#             */
/*   Updated: 2020/02/02 23:35:45 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int c, char **v)
{
	t_data *data;
	
	if (!c && !v)
	{
		return (0);
	}
	data->mlx->mlx_ptr = mlx_init();
	data->mlx->win_ptr = mlx_new_window(data->mlx->mlx_ptr, width, height, "fractol");
	data->mlx->img_ptr = mlx_new_image(data->mlx->mlx_ptr, width, height);
	
	data->mlx->img_data = (int *)mlx_get_data_addr(data->mlx->img_ptr, &data->bpp, &data->size_l, &data->endian);
	mandelbrot(data);
	mlx_hook(data->mlx->win_ptr, 2, 0, keypress, data);
	mlx_hook(data->mlx->win_ptr, 4, 0, mouse_press, data);
	
	mlx_loop(data->mlx->mlx_ptr);
	// }
	free(data);
	return (0);
}