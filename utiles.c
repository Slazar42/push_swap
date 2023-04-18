
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

int	ft_atoi(const char *str)
{
	int	result;
	int	s;
	int	i;

	result = 0;
	i = 0;
	s = 1;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ') && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * s);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	unsigned char	*sbs;
	int			i;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		sbs = malloc(ft_strlen(s) - start + 1);
	else
		sbs = malloc(len + 1);
	if (!sbs)
		return (0);
	i = 0;
	while (s[start] && len)
	{
		sbs[i] = s[start];
		start++;
		i++;
		len--;
	}
	sbs[i] = '\0';
	return ((char *)sbs);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int	len;

	len = ft_strlen(s1);
	ptr = malloc(len + 1);
	if (!ptr)
		return (0);
	while (*s1)
	{
		*ptr = *s1;
		s1++;
		ptr++;
	}
	*ptr = '\0';
	return (ptr - len);
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