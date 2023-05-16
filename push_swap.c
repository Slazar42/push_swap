/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 07:52:32 by slazar            #+#    #+#             */
/*   Updated: 2023/05/16 01:35:05 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_error()
{
	write(1,"Error\n",6);
	exit(0);
}
void	ft_check(char *str,int *n)
{
	int i=0;
	static int nbr = 0;
	// i = 0;
		if(!str[i])
				return;
		while (str[i] == ' ')
			i++;
		if(str[i] == '\0' && nbr == 0)
			ft_error();		
		if((str[i] == '-'  || str[i] == '+') && i++ && !(str[i] >= '0' && str[i] <= '9') || !str[i])
			ft_error();
		while(str[i] >= '0' && str[i] <= '9')
				{
					i++;
					nbr = 1;
				}
		if(str[i] != ' ' && str[i] != '\0')
			ft_error();
		*n += 1;
		ft_check(str + i,n);
}
int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c && *c)
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
void ft_duplicated(int *arr,int n)
{
	static int size;
	int i = n;

	if (size == 0)
		size = n;

	while (i < size && n >= 0)
	{
		if(arr[n] == arr[i+1])
				ft_error();
		i++;
	}
}
void *ft_atoiin(char *str,int *arr,int n)
{
	static int i;
	int sign ;
	long res ;
	
	res = 0;
	sign = 1;
	while(str[i] == ' ')
		i++;
	if (str[i] == '-' && i++)
		sign = -1;
	else if(str[i] == '+')
		i++;
	while(str[i] >= '0' && str[i] <= '9' && res <= 2147483648 )
		res = res * 10 + str[i++] - '0';
	if(res *sign < -2147483648 || res *sign > 2147483647)
		ft_error();
	arr[n] = res * sign ;
	ft_duplicated(arr,n);
	if(n >= 0)
		ft_atoiin(str,arr,n-1);
}
int indice_in_stack(int nb,int *stack)
{
	int i;
	
	i = 0;
	while (nb != stack[i++]);
	return(i - 1);
}
void	ft_range(t_stacks	*s)
{
	int range;
	int indice;
	int *sorted;
	sorted = sorted_arr(s->a,s->top_a);
		
	if (s->top_a <= 100)
		range = 15;
		// int b =0;
		// while (b <= s->top_a)
		// {
		// 	printf("%d\n",s->a[b]);
		// 	b++;
		// }
		// exit (0);
	// int i = 0;
	// // while (i <= s->top_a)
	// // {
	// 	printf("%d\n", s->a[s->top_a + 2]);
	// 	exit(0);
	// }
	while(s->top_a >= 0)
	{
		indice =  indice_in_stack(s->a[s->top_a],sorted);
		indice = s->top_a - indice;
		if(indice < range)
		{
			pa(s);
			rb(s);
			range++;
		}
		else if ((indice >= range - 15) && (indice <= range))
		{
			pa(s);
			range++;
		}
		else if (indice > range)
			ra(s);
		// int i = 0;
		// while (i <= s->top_a)
		// {
		// 	printf("======%d\n", s->a[i++]);
		// }
	}
	int bigest ;
	// int i = 0;
	// while (i <= s->top_a)
	// {
	// 	printf("%d\n", s->a[i++]);
	// }
	while (s->top_b >= 0)
	{
		// printf("top b is %d..%d\n",biggest(s->b,s->top_b), s->top_b);
		// else if(biggest(s->b,s->top_b)  == 0)
		// 	rrb(s);
		bigest = biggest(s->b,s->top_b);
		// printf("biggest = %d, i_b = %d, top_a = %d\n", s->b[biggest(s->b,s->top_b)],biggest(s->b,s->top_b),s->b[s->top_b]);
		if(s->b[bigest] == s->b[s->top_b])
		{
				pb(s);
		}
		rb(s);
		// if (bigest < s->top_b / 2 && bigest != 0)
		// 	rrb(s);
		// else if (bigest >= s->top_b / 2 && bigest != 0)
		// 	rb(s);
		// 	exit(0);
		// rrb(s);
		// else if(biggest(s->b,s->top_b)  == 0)
		// 	rrb(s);
	}
		// int i = 0;
		// while (i <= s->top_a)
		// {
		// 	printf("======%d\n", s->a[i++]);
		// }
		// printf("%d", s->a[s->top_a]);
	// int i = 0;
	// while (i <= s->top_a)
	// {
	// 	printf("%d\n", s->a[i++]);
	// }
	// printf("%d", s->a[0]);
}
int main(int ac, char **av)
{
	t_stacks s;

	char	*all= NULL;
	int		i;

	i = 0;
	int n = 0;
	s.top_b = -1;
	
	if (ac > 1)
	{
		i++;
		while (i < ac)
			{
				ft_check(av[i],&n);
				all = ft_strjoin(all,av[i++]);
			}
		s.top_a = n-1;
		s.a = calloc (n , sizeof(int));
		s.b = calloc (n , sizeof(int));
		ft_atoiin(all, s.a,n-1);
		if (sorted_or_not(&s))
			exit(0);
		if (s.top_a == 2)
			sort_3(&s);
		else if(s.top_a <= 4)
			sort_5(&s);
		else if(s.top_a > 4)
			ft_range(&s);
		// printf("\n%d\n", s.top_a);
		// while(s.top_a >= 0)
		// 	{printf("%d\n",s.a[s.top_a--]);}
		return(0);
	}
}