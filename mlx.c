/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:26:02 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/13 15:11:39 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_window(t_core *core)
{
    core->mlx = mlx_init();
    core->win = mlx_new_window(core->mlx, WIDTH, HEIGHT, "fractol");
    core->img = mlx_new_image(core->mlx, WIDTH, HEIGHT);
    core->imgpointer = mlx_get_data_addr(core->img, &core->bpp, &core->s1, &core->endian);
    fractolsInit(core);
    fractolPicker(core);
    mlx_put_image_to_window(core->mlx, core->win, core->img, 0, 0);
    mlx_key_hook(core->win, keysMap, core);
    mlx_mouse_hook(core->win, mouseKeys, core);
    mlx_hook(core->win, 6, 0, moves, exp);
    mlx_hook(core->win, 17, 0, closing, exp);
    mlx_loop(core->mlx);
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