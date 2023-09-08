/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions_mandatory3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:23:53 by slazar            #+#    #+#             */
/*   Updated: 2023/05/25 00:14:20 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stacks *st)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = st->a[i];
	while (i < st->top_a)
	{
		st->a[i] = st->a[i + 1];
		i++;
	}
	st->a[i] = tmp;
	i = 0;
	tmp = st->b[i];
	while (i < st->top_b)
	{
		st->b[i] = st->b[i + 1];
		i++;
	}
	st->b[i] = tmp;
	write(1, "rrr\n", 4);
}

int	*sorted_arr(int *arr, int top)
{
	int	i;
	int	temp;
	int	*arr_copy;

	arr_copy = malloc(sizeof(int) * top + 1);
	i = top;
	while (i >= 0)
	{
		arr_copy[i] = arr[i];
		i--;
	}
	i = 0;
	while (i <= top)
	{
		if (arr_copy[i] > arr_copy[i + 1])
		{
			temp = arr_copy[i];
			arr_copy[i] = arr_copy[i + 1];
			arr_copy[i + 1] = temp;
			i = -1;
		}
		i++;
	}
	return (arr_copy);
}

void	sort_3(t_stacks *s)
{
	if (biggest(s->a, s->top_a) == 1)
		rra(s);
	if (!sorted_or_not(s) && biggest(s->a, s->top_a) == 0)
		sa(s);
	if (biggest(s->a, s->top_a) == 2)
		ra(s);
	if (!sorted_or_not(s) && biggest(s->a, s->top_a) == 0)
		sa(s);
	if (!sorted_or_not(s) && biggest(s->a, s->top_a) == 2)
		sa(s);
}

void	sort_5(t_stacks *s)
{
	while (s->top_a > 2)
	{
		if (smallest(s->a, s->top_a) == s->top_a)
			pb(s);
		else if (smallest(s->a, s->top_a) <= s->top_a / 2)
			rra(s);
		else if (smallest(s->a, s->top_a) > s->top_a / 2)
			ra(s);
	}
	if (!sorted_or_not(s))
		sort_3(s);
	while (s->top_b >= 0)
		pa(s);
}
