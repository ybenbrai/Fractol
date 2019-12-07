/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:44:57 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/10/23 06:01:03 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ishex(char *hex)
{
	int i;

	i = 0;
	while (hex[i])
	{
		if (hex[0] == '0' && hex[1] == 'x')
		{
			i += 2;
			continue ;
		}
		if (hex[i] < '0' || hex[i] > '9')
			return (0);
		if (hex[i] < 'A' || hex[i] > 'F')
			return (0);
		i++;
	}
	return (1);
}
