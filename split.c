/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:59:27 by slazar            #+#    #+#             */
/*   Updated: 2023/04/17 09:01:41 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

int	len_word(const char *s, char c, int i)
{
	int	len_s;

	len_s = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len_s++;
	}
	return (len_s);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		len_s;
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (!s)
		return (0);
	tab = (char **)ft_calloc(word(s, c) + 1, sizeof(char *));
	if (!tab)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		len_s = len_word(s, c, i);
		if (++j < word(s, c))
			tab[j] = ft_substr(s, i, len_s);
		while (s[i] && s[i] != c)
			i++;
	}
	return (tab);
}