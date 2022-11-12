/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:09:21 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/11 21:24:24 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	ft_exit(char *str)
// {
// 	ft_putendl(str);
// 	exit(0);
// }

void check_arg(char *str, t_core *core)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		core->fractol = 1;
	else if (ft_strcmp(str, "julia") == 0)
		core->fractol = 2;
	else if (ft_strcmp(str, "burningship") == 0)
		core->fractol = 3;
	else
	{
		ft_putendl_fd("usage: ./fractol [mandelbrot, julia, burningship]", 2);
		exit(1);
	}
}
void controls()
{
	ft_putendl("Fractols:\n1. mandel\n2. julia\n3. burningship\n");
	ft_putendl("Controls:\n");
	ft_putendl("Move: Arrow Keys\nZoom: Page Up & Page Down");
	ft_putendl("Mouse Zoom: Scrool Wheel");
	ft_putendl("Iteration: Left Click & (+ -) Keys");
	ft_putendl("Zoom Reset: Space Bar\nJulia Activate: Right Click");
	ft_putendl("Color Change: Num Key 1-3\nHue Change: Num Key 4 & 5");
	exit(1);
}
void putimage(t_core *core, int x, int y, int color)
{
	int i;

	i = (x * (core->bpp / 8)) + (y * core->s1);
	core->imgpointer[i] = color;
	core->imgpointer[++i] = color >> 8;
	core->imgpointer[++i] = color >> 16;
}
unsigned int colormagic(int i, double x, double y)
{
	unsigned int color;
	double magic;
	double i2;
	t_c c;

	magic = sqrt(x * x + y * y);
	i2 = i + 1 - (log(2) / magic) / log(2);
	c.chan[0] = (unsigned char)(sin(0.026 * i2 + 4) * 230 + 25);
	c.chan[1] = (unsigned char)(sin(0.023 * i2 + 2) * 230 + 25);
	c.chan[2] = (unsigned char)(sin(0.01 * i2 + 1) * 230 + 25);
	color = (c.chan[0] << 16) + (c.chan[1] << 8) + (c.chan[2] + 255);
	return (color);
}
static void mandelassign(t_core *core)
{
	core->oldim = 0;
	core->oldre = core->oldim;
	core->newim = core->oldre;
	core->newre = core->newim;
}
static void mandelmagic(t_core *core)
{
	core->oldre = core->newre;
	core->oldim = core->newim;
	core->newre = core->oldre * core->oldre - core->oldim * core->oldim + core->pr;
	core->newim = 2 * core->oldre * core->oldim + core->pi;
}

void mandelfx(t_core *core)
{
	core->y = -1;
	while (++core->y < HEIGHT)
	{
		core->x = -1;
		while (++core->x < WIDTH)
		{
			core->pr = 1.5 * (core->x - WIDTH / 2) /
						   (0.5 * core->zoom * WIDTH) +
					   core->movex;
			core->pi = (core->y - HEIGHT / 2) /
						   (0.5 * core->zoom * HEIGHT) +
					   core->movey;
			mandelassign(core);
			core->i = -1;
			while (++core->i < core->maxinter)
			{
				mandelmagic(core);
				if ((core->newre * core->newre + core->newim * core->newim) > 4)
					break;
			}
			if (core->i < core->maxinter)
				putimage(core, core->x, core->y, (colormagic((core->color * core->i), core->x, core->y)));
			else
				putimage(core, core->x, core->y, 200);
		}
	}
}
void fractolPicker(t_core *core)
{
	// if (core->fractol == 1)
	// 	juliafx(core);
	if (core->fractol == 2)
		mandelfx(core);
	// if (core->fractol == 3)
	// 	shipfx(core);
	// if (core->fractol == 4)
	// 	carpetfx(core);
	// if (core->fractol == 5)
	// 	tricornfx(core);
	// if (core->fractol == 6)
	// 	juliacubedfx(core);
	// if (core->fractol == 7)
	// 	mandelcubedfx(core);
}
void ft_mandelbrotInit(t_core *core)
{
	core->zoom = 1;
	core->movex = 0;
	core->movey = 0;
	core->maxinter = 15;
}
void fractolsInit(t_core *core)
{
	if (core->fractol == 1)
		ft_mandelbrotInit(core);
	// else if (core->fractol == 2)
	// 	ft_juliaInit(core);
	// else if (core->fractol == 3)
	// 	ft_burningshipInit(core);
}

void redrawing(t_core *core)
{
	mlx_put_image_to_window(core->mlx, core->win, core->img, 0, 0);
	mlx_destroy_image(core->mlx, core->img);
	core->img = mlx_new_image(core->mlx, WIDTH, HEIGHT);
	core->imgpointer = mlx_get_data_addr(core->img,
										 &(core->bpp), &(core->s1), &(core->endian));
	fractolsInit(core);
	fractolPicker(core);
	mlx_put_image_to_window(core->mlx, core->win, core->img, 0, 0);
}
int directionsKeys(int key, t_core *core)
{
	if (key == 49)
		redrawing(core);
	if (key == 18)
	{
		core->color = 1;
		redrawing(core);
	}
	else if (key == 126)
		core->movey += .2 / core->zoom;
	else if (key == 125)
		core->movey -= .2 / core->zoom;
	else if (key == 124)
		core->movex += .2 / core->zoom;
	else if (key == 123)
		core->movex -= .2 / core->zoom;
	return (0);
}
int colorsKeys(int key, t_core *core)
{
	if (key == 19)
	{
		core->color = 0x247812;
		redrawing(core);
	}
	if (key == 20)
	{
		core->color = 2000;
		redrawing(core);
	}
	if (key == 21)
	{
		core->color += 50;
		redrawing(core);
	}
	if (key == 23)
	{
		core->color -= 10;
		redrawing(core);
	}
	return (0);
}
int keysMapping(int key, t_core *core)
{
	if (!(core->win))
		return (0);
	if (key == 53)
	{
		ft_putendl_fd("Exiting", 2);
		exit(0);
	}
	else if (key == 116)
		core->zoom *= pow(1.001, 70);
	else if (key == 121)
		core->zoom /= pow(1.001, 70);
	else if (key == 24)
		core->maxinter += 5;
	else if (key == 27)
		core->maxinter -= 5;
	colorsKeys(key, core);
	directionsKeys(key, core);
	fractolPicker(core);
	mlx_put_image_to_window(core->mlx, core->win, core->img, 0, 0);
	return (0);
}
void ft_window(t_core *core)
{
	core->mlx = mlx_init();
	core->win = mlx_new_window(core->mlx, WIDTH, HEIGHT, "fractol");
	core->img = mlx_new_image(core->mlx, WIDTH, HEIGHT);
	core->imgpointer = mlx_get_data_addr(core->img, &core->bpp, &core->s1, &core->endian);
	fractolsInit(core);
	fractolPicker(core);
	mlx_put_image_to_window(core->mlx, core->win, core->img, 0, 0);
	mlx_key_hook(core->win, keysMapping, core);
}
int main(int argc, char **argv)
{
	t_core *core;

	if (argc < 2)
		controls();
	if (!(core = (t_core *)ft_memalloc(sizeof(t_core))))
		return (0);
	core->color = 1;
	if (argc == 2)
	{
		check_arg(argv[1], core);
		ft_window(core);
	}

	// if(argv[1]){
	// if (ft_strcmp(check_arg(argv[1]),"Error") == 0)
	// ft_exit("Error: Usage ./fractol [mandelbrot, julia, burningship]");
	// core->mlx->mlx_ptr = mlx_init();
	// core->mlx->win_ptr = mlx_new_window(core->mlx->mlx_ptr, WIDTH, HEIGHT, "fractol");
	// core->mlx->img_ptr = mlx_new_image(core->mlx->mlx_ptr, WIDTH, HEIGHT);
	// core->mlx->img_core = (int *)mlx_get_data_addr(core->mlx->img_ptr, &core->mlx->bpp, &core->mlx->size_l, &core->mlx->endian);
	// if(ft_strcmp(check_arg(argv[1]),"mandelbrot") == 0){
	// 	core->mandel = (t_mandel *)malloc(sizeof(t_mandel));
	// 	mandelInit(core->mandel);
	// 	mandelbrot(core->mandel, core->mlx);
	// }
	// // else if(check_arg(argv[1]) == "julia")
	// // 	juliaInit(core);
	// // else if(check_arg(argv[1]) == "burningship")
	// 	mlx_hook(core->mlx->win_ptr, 2, 0, keypress, core);
	// 	mlx_hook(core->mlx->win_ptr, 4, 0, mouse_press, core);
	// // 	burningshipInit(core);
	// mlx_loop(core->mlx->mlx_ptr);
	// free(core->mlx);
	// free(core->mandel);
	free(core);
	// calling mandelbrot now
	//  mandelbrot(fractol);

	// puts("hello");

	// }
	// else
	// ft_exit("Error: Usage ./fractol [mandelbrot, julia, burningship]");
	return (0);
}