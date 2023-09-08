/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:31:19 by slazar            #+#    #+#             */
/*   Updated: 2023/05/24 23:31:30 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*cnc;
	int		i;

	i = 0;
	cnc = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!cnc)
		return (0);
	while (s1 && s1[i])
	{
		cnc[i] = s1[i];
		i++;
	}
	if (s1)
		free(s1);
	cnc[i++] = ' ';
	while (s2 && *s2)
	{
		cnc[i] = *s2;
		s2++;
		i++;
	}
	cnc[i] = 0;
	return (cnc);
}
