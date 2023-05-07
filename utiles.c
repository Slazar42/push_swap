
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:10:30 by slazar            #+#    #+#             */
/*   Updated: 2023/04/17 09:10:31 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ft_atoi(char *str)
// {
// 	int	result;
// 	int	s;
// 	int	i;

// 	result = 0;
// 	i = 0;
// 	s = 1;
// 	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ') && str[i])
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			s *= -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		result = (result * 10) + (str[i] - '0');
// 		i++;
// 	}
// 	return (result * s);
// }

char	*ft_calloc(int count, int size)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc(count * size);
	if (!result)
		return (0);
	while (i < (count * size))
	{
		*(result + i) = 0;
		i++;
	}
	return (result);
}

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
	if(s1)
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
