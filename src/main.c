/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:09:21 by ybenbrai          #+#    #+#             */
/*   Updated: 2020/02/03 18:52:34 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



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