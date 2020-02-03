/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coreTools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:52:48 by ybenbrai          #+#    #+#             */
/*   Updated: 2020/02/03 18:53:06 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlxInit(t_core *core)
{
	core->mlx.mlx_ptr = mlx_init();

	core->mlx.win_ptr = mlx_new_window(core->mlx.mlx_ptr, width, height, "fractol");
	core->mlx.img_ptr = mlx_new_image(core->mlx.mlx_ptr, width, height);

	core->mlx.img_core = (int *)mlx_get_data_addr(core->mlx.img_ptr, &core->mlx.bpp, &core->mlx.size_l, &core->mlx.endian);
}