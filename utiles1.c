/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:10:30 by slazar            #+#    #+#             */
/*   Updated: 2023/05/27 20:47:31 by slazar           ###   ########.fr       */
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

void	ft_duplicated(int *arr, int n)
{
	static int	size;
	int			i;

	i = n;
	if (size == 0)
		size = n;
	while (i < size && n >= 0)
	{
		if (arr[n] == arr[i + 1])
			ft_error();
		i++;
	}
}

void	ft_atoiin(char *str, int *arr, int n)
{
	static int	i;
	int			sign;
	long		res;

	res = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' && i++)
		sign = -1;
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && res <= 2147483648)
		res = res * 10 + str[i++] - '0';
	if (res * sign < -2147483648 || res * sign > 2147483647)
		ft_error();
	arr[n] = res * sign;
	ft_duplicated(arr, n);
	if (n >= 0)
		ft_atoiin(str, arr, n - 1);
	if (n < 0)
		free(str);
}

// void	ft_check(char *str, int *n)
// {
// 	int			i;
// 	static int	nbr;

// 	i = 0;
// 	nbr = 0;
// 	if (!str[i])
// 		return ;
// 	while (str[i] == ' ')
// 		i++;
// 	if (str[i] == '\0' && nbr == 0)
// 		ft_error();
// 	if (((str[i] == '-' || str[i] == '+') && i++ && !(str[i] >= '0'
// 				&& str[i] <= '9')) || !str[i])
// 		ft_error();
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		i++;
// 		nbr = 1;
// 	}
// 	if (str[i] != ' ' && str[i] != '\0')
// 		ft_error();
// 	while (str[i] == ' ')
// 		i++;
// 	*n += 1;
// 	ft_check(str + i, n);
// }

void	ft_check(char *av, int *n)
{
	int	i;

	i = 0;
	if (!av[i])
		ft_error();
	while (av[i])
	{
		while (av[i] == ' ')
			i++;
		if (((av[i] == '-' || av[i] == '+') && ++i && !(av[i] >= '0'
					&& av[i] <= '9')) || !av[i])
			ft_error();
		while (av[i] >= '0' && av[i] <= '9')
			i++;
		if (av[i] != ' ' && av[i] != '\0')
			ft_error();
		while (av[i] == ' ')
			i++;
		(*n)++;
	}
}

int	sorted_or_not(t_stacks *s)
{
	int	i;

	i = 0;
	while (i < s->top_a)
	{
		if (s->a[i] < s->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
