/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coreTools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:52:48 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/10 23:11:19 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlxInit(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();

	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "fractol");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);

	mlx->img_core = (int *)mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->size_l, &mlx->endian);
	mlx_loop(mlx->mlx_ptr);
}