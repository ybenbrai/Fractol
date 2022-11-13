/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:09:21 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/13 15:03:20 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"







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
	else{
		controls();
	}
	return (0);
}