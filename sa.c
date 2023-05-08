/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:09:56 by slazar            #+#    #+#             */
/*   Updated: 2023/04/20 09:12:39 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *st)
{
	int	tmp;
	if( st->top_a > 1)
	{
		tmp = st->a[st->top_a];
		st->a[st->top_a ] = st->a[st->top_a -1];
		st->a[st->top_a -1] = tmp;
		write(1, "sa\n", 3);
	}
}
void	sb(t_stacks *st)
{
	int	tmp;
	if( st->top_b > 1)
	{
		tmp = st->a[st->top_b];
		st->a[st->top_b ] = st->a[st->top_b -1];
		st->a[st->top_b -1] = tmp;
		write(1, "sb\n", 3);
	}
}
void	ra(t_stacks *st)
{
	int tmp;
	int k;
	k = st->top_a;
	if(st->top_a > 1)
	{
		tmp = st->a[st->top_a];
		while (k > 0)
		{
			st->a[k]=st->a[k-1];
			k--;
		}
		st->a[k] = tmp;
		write(1, "ra\n", 3);
	}
}
void	rb(t_stacks *st)
{
	int tmp;
	int k;
	k = st->top_b;
	if(st->top_b > 1)
	{
		tmp = st->a[st->top_b];
		while (k > 0)
		{
			st->b[k]=st->b[k-1];
			k--;
		}
		st->b[k] = tmp;
		write(1, "rb\n", 3);
	}
}

void	pa(t_stacks *st)
{
	if(st->top_a < 0)
		return;
	st->top_b += 1;
	st->b[st->top_b] = st->a[st->top_a];
	st->top_a -= 1;
	write(1, "pa\n", 3);
}

void	pb(t_stacks *st)
{
	if(st->top_b < 0)
		return;
	st->top_a += 1;
	st->a[st->top_a] = st->b[st->top_b];
	st->top_b -= 1;
	write(1, "pb\n", 3);
}

void	rra(t_stacks *st)
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
	write(1, "rra\n", 4);
}

void	rrb(t_stacks *st)
{
	int	tmp;
	int	i;

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
	if( st->top_a > 1)
	{
		tmp = st->a[st->top_a];
		st->a[st->top_a ] = st->a[st->top_a -1];
		st->a[st->top_a -1] = tmp;
	}
	if( st->top_a > 1)
	{
		tmp = st->a[st->top_a];
		st->a[st->top_a ] = st->a[st->top_a -1];
		st->a[st->top_a -1] = tmp;
	}
	write(1, "ss\n", 3);
}

int 	biggest(t_stacks *s,int n)
{
	static int big;
	static int i;
	if (s->a[n] > big)
		{
			big = s->a[n];
			i = n;
		}
	if(n <= s->top_a )
		biggest(s,++n);
	return(i);
}

int		smallest(t_stacks *s,int n)
{
	int small;
	int i;

	small = s->a[n];
	while (n <= s->top_a)
	{
		if (s->a[n] < small)
		{
			i = n;
			small = s->a[n];
		}
		n++;
	}
	return(i);
}

int sorted_or_not(t_stacks *s)
{
	int i;
	i = 0;
	while (i < s->top_a)
	{
		if(s->a[i] < s->a[i + 1])
			return (0);
		i++;
	}
	return(1);
}

void sort_3(t_stacks *s)
{
	int big;
	int small;
	big = biggest(s,0);
	small = smallest(s,0);
	if(small == 1)
		sa(s);
	else if(big == 2)
		ra(s);
	else if(big == 1)
		rra(s);
	if(!sorted_or_not(s))
		sort_3(s);
}

void	sort_5(t_stacks *s)
{
	// printf("%d\n", s->top_a);
	while (s->top_a > 2)
	{
		if(smallest(s,0) <= s->top_a / 2)
		{
			while (s->top_a != smallest(s,0))
				ra(s);
		}
		else if(smallest(s,0) > s->top_a / 2)
		{
			while (s->top_a != smallest(s,0))
				rra(s);
		}
		pa(s);
	}
	sort_3(s);
	while (s->top_b + 1)
		pb(s);
	

}

