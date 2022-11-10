/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:09:21 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/10 23:44:55 by ybenbrai         ###   ########.fr       */
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
	t_core *core;
	
	(void)argc;
	if(argv[1]){
	if (ft_strcmp(check_arg(argv[1]),"Error") == 0)
		ft_exit("Error: Usage ./fractol [mandelbrot, julia, burningship]");
	core = (t_core *)malloc(sizeof(t_core));
	core->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	core->mlx->mlx_ptr = mlx_init();
	core->mlx->win_ptr = mlx_new_window(core->mlx->mlx_ptr, WIDTH, HEIGHT, "fractol");
	core->mlx->img_ptr = mlx_new_image(core->mlx->mlx_ptr, WIDTH, HEIGHT);
	core->mlx->img_core = (int *)mlx_get_data_addr(core->mlx->img_ptr, &core->mlx->bpp, &core->mlx->size_l, &core->mlx->endian);
	if(ft_strcmp(check_arg(argv[1]),"mandelbrot") == 0){
		core->mandel = (t_mandel *)malloc(sizeof(t_mandel));
		mandelInit(core->mandel);
		mandelbrot(core->mandel, core->mlx);
	}
	// else if(check_arg(argv[1]) == "julia")
	// 	juliaInit(core);
	// else if(check_arg(argv[1]) == "burningship")
		mlx_hook(core->mlx->win_ptr, 2, 0, keypress, core);
		mlx_hook(core->mlx->win_ptr, 4, 0, mouse_press, core);
	// 	burningshipInit(core);
	mlx_loop(core->mlx->mlx_ptr);
	free(core->mlx);
	free(core->mandel);
	free(core);
		//calling mandelbrot now
		// mandelbrot(fractol);
		
		puts("hello");

	}
	else
		ft_exit("Error: Usage ./fractol [mandelbrot, julia, burningship]");
	return(0);
}