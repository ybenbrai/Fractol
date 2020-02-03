/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:09:21 by ybenbrai          #+#    #+#             */
/*   Updated: 2020/02/03 18:33:01 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void	mandelInit(t_data *data)
{
	data->quality = 100;
	data->hexa = 1;
	data->octa = 8;
	data->right_left = 2.0;
	data->zoom_in = 4.0;
	data->up_down = 2.0;
}
int	main(int c, char **v)
{
	//declaration of the core data
	t_data *data;

	//cheking the arguments
	if (!c && !v)
		return (0);
	else
	{
		//alocate for the date if the arguments are there
		data = (t_data *)malloc(sizeof(t_data));

		//initialise the variables of mandelbrot
		mandelInit(data);

		//initilise the variables of mlx
	data->mlx.mlx_ptr = mlx_init();
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr, width, height, "fractol");
	data->mlx.img_ptr = mlx_new_image(data->mlx.mlx_ptr, width, height);

	data->mlx.img_data = (int *)mlx_get_data_addr(data->mlx.img_ptr, &data->bpp, &data->size_l, &data->endian);
	mandelbrot(data);
	mlx_hook(data->mlx.win_ptr, 2, 0, keypress, data);
	mlx_hook(data->mlx.win_ptr, 4, 0, mouse_press, data);

		mlx_loop(data->mlx.mlx_ptr);
	}
	return(0);
}