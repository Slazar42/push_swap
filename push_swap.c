/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 07:52:32 by slazar            #+#    #+#             */
/*   Updated: 2023/04/21 03:10:09 by slazar           ###   ########.fr       */
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
		if((str[i] == '-'  || str[i] == '+') && i++ && !(str[i] >= '0' && str[i] <= '9' ) || str[i] == '\0')
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
int main(int ac, char **av)
{
	t_stacks s;

	char	*all= NULL;
	int		i;

	i = 0;
	int n = 0;
	s.top_b = -1;
	if (ac >= 1)
	{
		i++;
		while (i < ac)
			{
				ft_check(av[i],&n);
				all = ft_strjoin(all,av[i++]);
			}
		s.top_a = n-1;
		s.a = malloc (n * sizeof(int));
		s.b = malloc (n * sizeof(int));
		// printf("%s\n",all);
		ft_atoiin(all, s.a,n-1);
		i=0;
		for(int j = n-1;j>=0;j--)
			{printf("%d\n",s.a[j]);}
		swap_a(&s);
			{printf("\n88888888888888888888888888888888888888888888888888888888888888888888888\n");}
		for(int j = n-1;j>=0;j--)
			{printf("%d\n",s.a[j]);}
		ra(&s);
			{printf("\n88888888888888888888888888888888888888888888888888888888888888888888888\n");}
		for(int j = n-1;j>=0;j--)
			{printf("%d\n",s.a[j]);}
		// if(n  <= 99)
		// 	ft_sort(&s);
		// ft_big(&s);
		return(0);
	}
}