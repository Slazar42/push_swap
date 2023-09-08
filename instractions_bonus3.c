/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions_bonus3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:21:11 by slazar            #+#    #+#             */
/*   Updated: 2023/05/24 23:21:41 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr_b(t_stacks *st)
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
}
