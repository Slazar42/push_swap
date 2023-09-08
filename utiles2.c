/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:29:00 by slazar            #+#    #+#             */
/*   Updated: 2023/05/27 00:06:59 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest(int *a, int top)
{
	int	small;
	int	i;
	int	t;

	i = 0;
	t = 0;
	small = a[i];
	while (i <= top)
	{
		if (a[i] < small)
		{
			small = a[i];
			t = i;
		}
		i++;
	}
	return (t);
}

int	biggest(int *a, int top)
{
	int	big;
	int	i;
	int	t;

	i = 0;
	t = 0;
	big = a[0];
	while (i <= top)
	{
		if (a[i] > big)
		{
			big = a[i];
			t = i;
		}
		i++;
	}
	return (t);
}

void	fill_stack(int ac, char **av, t_stacks *s)
{
	char	*all;
	int		i;
	int		n;

	all = NULL;
	s->readed = 1;
	s->i = 0;
	n = 0;
	i = 1;
	s->top_b = -1;
	while (i < ac)
	{
		ft_check(av[i], &n);
		all = ft_strjoin(all, av[i++]);
	}
	s->top_a = n - 1;
	s->a = (int *)ft_calloc(n, sizeof(int));
	s->b = (int *)ft_calloc(n, sizeof(int));
	if (!s->a || !s->b)
		exit(1);
	ft_atoiin(all, s->a, n - 1);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

char	*ft_calloc(int count, int size)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc(count * size);
	if (!result)
		exit(1);
	while (i < (count * size))
	{
		*(result + i) = 0;
		i++;
	}
	return (result);
}
