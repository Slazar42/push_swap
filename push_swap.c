/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 07:52:32 by slazar            #+#    #+#             */
/*   Updated: 2023/05/27 20:42:04 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *c)
{
	while (*c)
	{
		write(1, c, 1);
		c++;
	}
}

int	indice_in_stack(int nb, int *stack)
{
	int	i;

	i = 0;
	while (nb != stack[i++])
		;
	return (i - 1);
}

void	range_norm(t_stacks *s, int range, int first_range)
{
	int	indice;
	int	*sorted;
	int	size;

	sorted = sorted_arr(s->a, s->top_a);
	size = s->top_a;
	while (s->top_a >= 0)
	{
		indice = indice_in_stack(s->a[s->top_a], sorted);
		if (indice <= range - first_range)
		{
			pb(s);
			rb(s);
			if (range <= size)
				range++;
		}
		else if ((indice >= range - first_range) && (indice <= range))
		{
			pb(s);
			if (range <= size)
				range++;
		}
		else if (indice > range)
			ra(s);
	}
}

void	ft_range(t_stacks *s)
{
	int	bigestt;
	int	range;

	if (s->top_a < 100)
		range = 15;
	else if (s->top_a >= 100 && s->top_a <= 500)
		range = 35;
	else
		range = 50;
	range_norm(s, range, range);
	while (s->top_b >= 0)
	{
		bigestt = biggest(s->b, s->top_b);
		if (bigestt == s->top_b)
			pa(s);
		else if (s->top_b - bigestt <= bigestt)
			rb(s);
		else if (s->top_b - bigestt > bigestt)
			rrb(s);
	}
}

int	main(int ac, char **av)
{
	t_stacks	s;

	if (ac > 1)
	{
		fill_stack(ac, av, &s);
		if (sorted_or_not(&s))
			exit(0);
		if (s.top_a == 2)
			sort_3(&s);
		else if (s.top_a < 5)
			sort_5(&s);
		else if (s.top_a >= 5)
			ft_range(&s);
	}
}
