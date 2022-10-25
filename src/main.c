/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:09:21 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/10/25 22:20:24 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exit(char *str)
{
	ft_putendl(str);
	exit(0);
}

char	*check_arg(char *str)
{
	if(ft_strcmp(str, "mandelbrot") == 0)
		return("mandelbrot");
	else if(ft_strcmp(str, "julia") == 0)
		return("julia");
	else if(ft_strcmp(str, "burningship") == 0)
		return("burningship");
	else
		return("Error");
	
}

int	main(int argc, char **argv)
{
	t_fractol *fractol;
	(void)argc;
	if(argv[1]){
		
	if (ft_strcmp(check_arg(argv[1]), "Error") == 0)
		ft_exit("Error: Usage ./fractol [mandelbrot, julia, burningship]");
	// if (ft_strcmp(check_arg(argv[1]), "Error") == 0)
	// 	ft_exit("Error: Usage ./fractol [mandelbrot, julia, burningship]");
	// //allocating memory for the fractol structure
	// if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
	// 	ft_exit("Error: Memory allocation failed");
	//initializing the fractol structure
	// fractol->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	// fractol->mandel = (t_mandel *)malloc(sizeof(t_mandel));
	// fractol->julia = (t_julia *)malloc(sizeof(t_julia));
	// fractol->burningship = (t_burningship *)malloc(sizeof(t_burningship));
	//initializing the mlx structure
		//alocate for the date if the arguments are there
		fractol = (t_fractol *)malloc(sizeof(t_fractol));

		//initialise the variables of mandelbrot
		mandelInit(fractol);

		//initilise the variables of mlx
		mlxInit(fractol);
		
		//calling mandelbrot now
		mandelbrot(fractol);
		
		mlx_hook(fractol->mlx.win_ptr, 2, 0, keypress, fractol);
		mlx_hook(fractol->mlx.win_ptr, 4, 0, mouse_press, fractol);
		mlx_loop(fractol->mlx.mlx_ptr);

	}
	else
		ft_exit("Error: Usage ./fractol [mandelbrot, julia, burningship]");
	return(0);
}