/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:09:56 by slazar            #+#    #+#             */
/*   Updated: 2023/05/20 18:24:58 by slazar           ###   ########.fr       */
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
	if(st->top_a > 1)
	{
		k = st->top_a;
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
	if(st->top_b >= 1)
	{
		k = st->top_b;
		tmp = st->b[st->top_b];
		while (k > 0)
		{
			st->b[k]=st->b[k-1];
			k--;
		}
		st->b[k] = tmp;
		write(1, "rb\n", 3);
	}
	// write(1, "ss\n", 3);
}

void	pb(t_stacks *st)
{
	if(st->top_a < 0)
		return;
	st->top_b += 1;
	st->b[st->top_b] = st->a[st->top_a];
	st->top_a -= 1;
	write(1, "pb\n", 3);
}

void	pa(t_stacks *st)
{
	if(st->top_b < 0)
		return;
	st->top_a += 1;
	st->a[st->top_a] = st->b[st->top_b];
	st->top_b -= 1;
	write(1, "pa\n", 3);
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
	if(st->top_b < 1)
		return;
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
	if( st->top_b > 1)
	{
		tmp = st->a[st->top_b];
		st->a[st->top_b ] = st->a[st->top_b -1];
		st->a[st->top_b -1] = tmp;
	}
	write(1, "ss\n", 3);
}
void	rr(t_stacks *st)
{
	int tmp;
	int k;
	if(st->top_a > 1)
	{
		k = st->top_a;
		tmp = st->a[st->top_a];
		while (k > 0)
		{
			st->a[k]=st->a[k-1];
			k--;
		}
		st->a[k] = tmp;
	}
	if (st->top_b > 1)
	{
		k = st->top_b;
		tmp = st->a[st->top_b];
		while (k > 0)
		{
			st->b[k]=st->b[k-1];
			k--;
		}
		st->b[k] = tmp;
	}
	write(1, "rr\n", 3);
}

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

int *sorted_arr(int *arr,int top)
{
	int i;
	int temp;
	int *arr_copy;

	arr_copy = malloc(sizeof(int) * top + 1);
	i = top;
	while (i >= 0)
	{
		arr_copy[i] = arr[i];
		i--;
	}
	i = 0;
	while(i <= top)
	{
		if(arr_copy[i] > arr_copy[i + 1])
		{
			temp = arr_copy[i];
			arr_copy[i] = arr_copy[i + 1];
			arr_copy[i + 1] = temp;
			i = -1;
		}
		i++;
	}
	return(arr_copy);
}

int		smallest(int *a,int top)
{
	int small;
	int i;
	int t;

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

int		biggest(int *a,int top)
{
	int big;
	int i;
	int t;
		
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
	return(t);
}

	
void sort_3(t_stacks *s)
{
	if(biggest(s->a,s->top_a) == 1)
		rra(s);
	if(!sorted_or_not(s) && biggest(s->a,s->top_a) == 0)
		sa(s);
	if(biggest(s->a,s->top_a) == 2)
		ra(s);
	if(!sorted_or_not(s) && biggest(s->a,s->top_a) == 0)
		sa(s);
	if(!sorted_or_not(s) && biggest(s->a,s->top_a) == 2)
		sa(s);
}

void	sort_5(t_stacks *s)
{

	while (s->top_a > 2)
	{
		if(smallest(s->a,s->top_a) == s->top_a)
			pb(s);
		else if (smallest(s->a,s->top_a) <= s->top_a / 2)
			rra(s);
		else if (smallest(s->a,s->top_a) > s->top_a / 2)
			ra(s);
	}
	if(!sorted_or_not(s))
		sort_3(s);
	while (s->top_b >= 0)
		pa(s);
}
