/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:09:21 by ybenbrai          #+#    #+#             */
/*   Updated: 2020/02/03 17:48:29 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
t_data	*mlxInit(t_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr, width, height, "fractol");
	data->mlx.img_ptr = mlx_new_image(data->mlx.mlx_ptr, width, height);
	data->mlx.img_data = (int *)mlx_get_data_addr(data->mlx.img_ptr, &data->bpp, &data->size_l, &data->endian);
	mlx_hook(data->mlx.win_ptr, 2, 0, keypress, data);
	mlx_hook(data->mlx.win_ptr, 4, 0, mouse_press, data);
	return(data);
}

int	main(int c, char **v)
{
	t_data data;


	// data = NULL;	
	// data->mlx = NULL;
	// data->mandel = NULL;
	if (!c && !v)
		return (0);
	// data = corAlloc(data);
	mlxInit(&data);
	mandel_init(&data);
	mandelbrot(&data);
	
	mlx_loop(data.mlx.mlx_ptr);
	return (0);
}