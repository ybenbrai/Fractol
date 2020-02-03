/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:09:21 by ybenbrai          #+#    #+#             */
/*   Updated: 2020/02/03 18:46:42 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void	mandelInit(t_core *core)
{
	core->mandel.quality = 100;
	core->mandel.hexa = 1;
	core->mandel.octa = 8;
	core->mandel.right_left = 2.0;
	core->mandel.zoom_in = 4.0;
	core->mandel.up_down = 2.0;
}

void	mlxInit(t_core *core)
{
	core->mlx.mlx_ptr = mlx_init();

	core->mlx.win_ptr = mlx_new_window(core->mlx.mlx_ptr, width, height, "fractol");
	core->mlx.img_ptr = mlx_new_image(core->mlx.mlx_ptr, width, height);

	core->mlx.img_core = (int *)mlx_get_data_addr(core->mlx.img_ptr, &core->mlx.bpp, &core->mlx.size_l, &core->mlx.endian);
}
int	main(int c, char **v)
{
	//declaration of the core core
	t_core *core;

	//cheking the arguments
	if (!c && !v)
		return (0);
	else
	{
		//alocate for the date if the arguments are there
		core = (t_core *)malloc(sizeof(t_core));

		//initialise the variables of mandelbrot
		mandelInit(core);

		//initilise the variables of mlx
		mlxInit(core);
		
		//calling mandelbrot now
		mandelbrot(core);
		
		mlx_hook(core->mlx.win_ptr, 2, 0, keypress, core);
		mlx_hook(core->mlx.win_ptr, 4, 0, mouse_press, core);
		mlx_loop(core->mlx.mlx_ptr);
	}
	return(0);
}