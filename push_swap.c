/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 07:52:32 by slazar            #+#    #+#             */
/*   Updated: 2023/04/21 03:10:09 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (*c)
	{
		c++;
		i++;
	}
	return (i);
}
void	ft_putstr(char *c)
{
	while (*c)
	{
		write(1, c, 1);
		c++;
	}
}


int main(int ac, char **av)
{
	// t_stacks ps;

	char	*all;
	int		i;

	i = 0;
	if (ac >= 1)
	{
		av++;
		while (av[i])
		{
			all = ft_strjoin(all,av[i++]);
		}
		av = ft_split(*av,' ');
	}
}