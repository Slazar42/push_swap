
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:10:30 by slazar            #+#    #+#             */
/*   Updated: 2023/04/17 09:10:31 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void	ft_check(char *str,int *n)
{
	int i;

	i=0;
	static int nbr = 0;
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
void fill_stack(int ac,char **av,t_stacks *s)
{
	char	*all= NULL;
	int		i;
	int n ;
	
	s->readed = 1;
	s->i = 0;
	n = 0;
	i = 1;
	s->top_b = -1;
	while (i < ac)
	{
		ft_check(av[i],&n);
		all = ft_strjoin(all,av[i++]);
	}
	s->top_a = n-1;
	s->a = ft_calloc (n , sizeof(int));
	s->b = ft_calloc (n , sizeof(int));
	ft_atoiin(all, s->a,n-1);
}

void ft_error()
{
	write(2,"Error\n",6);
	exit(1);
}
char	*ft_calloc(int count, int size)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc(count * size);
	if (!result)
		return (0);
	while (i < (count * size))
	{
		*(result + i) = 0;
		i++;
	}
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*cnc;
	int		i;

	i = 0;
	cnc = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!cnc)
		return (0);
	while (s1 && s1[i])
	{
		cnc[i] = s1[i];
		i++;
	}
	if(s1)
		free(s1);
	cnc[i++] = ' ';
	while (s2 && *s2)
	{
		cnc[i] = *s2;
		s2++;
		i++;
	}
	cnc[i] = 0;
	return (cnc);
}

