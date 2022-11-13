/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:33:01 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/13 14:51:58 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void fractolsInit(t_core *core)
{
	if (core->fractol == 1)
		ft_mandelbrotInit(core);
	// else if (core->fractol == 2)
	// 	ft_juliaInit(core);
	// else if (core->fractol == 3)
	// 	ft_burningshipInit(core);
}

void fractolPicker(t_core *core)
{
	if (core->fractol == 1)
		mandelfx(core);
	// if (core->fractol == 2)
	// 	juliafx(core);
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

