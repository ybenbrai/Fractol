/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:50:57 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/03/30 13:53:45 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fraiche;

	fraiche = NULL;
	if (s1 && s2)
	{
		fraiche = (char *)malloc(sizeof(char) *
				(ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!fraiche)
			return (NULL);
		ft_strcpy(fraiche, s1);
		ft_strcat(fraiche, s2);
	}
	return (fraiche);
}
