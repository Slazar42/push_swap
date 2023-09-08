/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions_mandatory1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:09:56 by slazar            #+#    #+#             */
/*   Updated: 2023/05/25 00:13:34 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *st)
{
	if (st->top_b < 0)
		return ;
	st->top_a += 1;
	st->a[st->top_a] = st->b[st->top_b];
	st->top_b -= 1;
	write(1, "pa\n", 3);
}

void	rra(t_stacks *st)
{
	int	tmp;
	int	i;

	if (st->top_a < 1)
		return ;
	i = 0;
	tmp = st->a[i];
	while (i < st->top_a)
	{
		st->a[i] = st->a[i + 1];
		i++;
	}
	st->a[i] = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_stacks *st)
{
	int	tmp;
	int	i;

	if (st->top_b < 1)
		return ;
	i = 0;
	tmp = st->b[i];
	while (i < st->top_b)
	{
		st->b[i] = st->b[i + 1];
		i++;
	}
	st->b[i] = tmp;
	write(1, "rrb\n", 4);
}

void	ss(t_stacks *st)
{
	int	tmp;

	if (st->top_a >= 1 && st->top_b >= 1)
	{
		tmp = st->a[st->top_a];
		st->a[st->top_a] = st->a[st->top_a - 1];
		st->a[st->top_a - 1] = tmp;
		tmp = st->a[st->top_b];
		st->b[st->top_b] = st->b[st->top_b - 1];
		st->b[st->top_b - 1] = tmp;
		write(1, "ss\n", 3);
	}
}

void	rr(t_stacks *st)
{
	int	tmp;
	int	k;

	if (st->top_a > 0 && st->top_b > 0)
	{
		k = st->top_a;
		tmp = st->a[st->top_a];
		while (k > 0)
		{
			st->a[k] = st->a[k - 1];
			k--;
		}
		st->a[k] = tmp;
		k = st->top_b;
		tmp = st->a[st->top_b];
		while (k > 0)
		{
			st->b[k] = st->b[k - 1];
			k--;
		}
		st->b[k] = tmp;
		write(1, "rr\n", 3);
	}
}
