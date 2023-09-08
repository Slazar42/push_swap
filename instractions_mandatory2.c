/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions_mandatory2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:23:16 by slazar            #+#    #+#             */
/*   Updated: 2023/05/25 00:13:52 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *st)
{
	int	tmp;

	if (st->top_a >= 1)
	{
		tmp = st->a[st->top_a];
		st->a[st->top_a] = st->a[st->top_a - 1];
		st->a[st->top_a - 1] = tmp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_stacks *st)
{
	int	tmp;

	if (st->top_b >= 1)
	{
		tmp = st->a[st->top_b];
		st->a[st->top_b] = st->a[st->top_b - 1];
		st->a[st->top_b - 1] = tmp;
		write(1, "sb\n", 3);
	}
}

void	ra(t_stacks *st)
{
	int	tmp;
	int	k;

	if (st->top_a >= 1)
	{
		k = st->top_a;
		tmp = st->a[st->top_a];
		while (k > 0)
		{
			st->a[k] = st->a[k - 1];
			k--;
		}
		st->a[k] = tmp;
		write(1, "ra\n", 3);
	}
}

void	rb(t_stacks *st)
{
	int	tmp;
	int	k;

	if (st->top_b >= 1)
	{
		k = st->top_b;
		tmp = st->b[st->top_b];
		while (k > 0)
		{
			st->b[k] = st->b[k - 1];
			k--;
		}
		st->b[k] = tmp;
		write(1, "rb\n", 3);
	}
}

void	pb(t_stacks *st)
{
	if (st->top_a < 0)
		return ;
	st->top_b += 1;
	st->b[st->top_b] = st->a[st->top_a];
	st->top_a -= 1;
	write(1, "pb\n", 3);
}
