/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:09:56 by slazar            #+#    #+#             */
/*   Updated: 2023/05/13 04:09:36 by slazar           ###   ########.fr       */
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
	if(st->top_b > 1)
	{
		k = st->top_b;
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
	i = 0;
	while(i <= top)
	{
		if(arr[i] < arr[i + 1])
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			i = -1;
		}
		i++;
	}
	return(arr);
}

// int 	biggest(int a)
// {
// 	static int big;
// 	static int i;
// 	if(!n)
// 		big = s->a[n];
// 	if (s->a[n] > big)
// 		{
// 			big = s->a[n];
// 			i = n;
// 		}
// 	if(++n <= s->top_a )
// 		biggest(s,n);
// 	return(i);
// }

int		smallest(int *a,int top)
{
	int small;
	int i;
		
	i = 0;
	small = a[i];
	while (i <= top)
	{
		if (a[i] < small)
			small = a[i];
		i++;
	}
	return(i - top);
}

int		biggest(int *a,int top)
{
	int big;
	int i;
	int t;
		
	i = 0;
	t = 0;
	big = a[top];
	while (i <= top)
	{
		if (a[i] >= big)
			{
				big = a[i];
				t = i;
			}
		i++;
	}
	return(t);
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
	if(biggest(s->a,s->top_a) == 1)
		rra(s);
	if(sorted_or_not(s))
		exit(0);
	else if ((biggest(s->a,s->top_a) == 0))
	{
		sa(s);
		exit(0);
	}
	if(biggest(s->a,s->top_a) == 2)
		ra(s);
	if(sorted_or_not(s))
		exit(0);
	else if (biggest(s->a,s->top_a) == 0)
	{
		ra(s);
		exit(0)	;		
	}
	sa(s);
	exit(0);
}

void	sort_5(t_stacks *s)
{
	while (s->top_a > 2)
	{
		if(smallest(s->a,s->top_a) <= s->top_a / 2)
		{
			while (s->top_a != smallest(s->a,s->top_a))
				ra(s);
		}
		else if(smallest(s->a,s->top_a) > s->top_a / 2)
		{
			while (s->top_a != smallest(s->a,s->top_a))
				rra(s);
		}
		pa(s);
	}
	sort_3(s);
	while (s->top_b + 1)
		pb(s);

}

