/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:05:35 by slazar            #+#    #+#             */
/*   Updated: 2023/05/27 20:47:59 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	readed_check(char *buffer, t_stacks *s)
{
	if (buffer[0] == 'r' && buffer[1] == 'r' && buffer[2] == '\n')
		rr_b(s);
	else if (buffer[0] == 'r' && buffer[1] == 'a' && buffer[2] == '\n')
		ra_b(s);
	else if (buffer[0] == 'r' && buffer[1] == 'b' && buffer[2] == '\n')
		rb_b(s);
	else if (buffer[0] == 's' && buffer[1] == 'a' && buffer[2] == '\n')
		sa_b(s);
	else if (buffer[0] == 's' && buffer[1] == 'b' && buffer[2] == '\n')
		sb_b(s);
	else if (buffer[0] == 's' && buffer[1] == 's' && buffer[2] == '\n')
		ss_b(s);
	else if (buffer[0] == 'p' && buffer[1] == 'a' && buffer[2] == '\n')
		pa_b(s);
	else if (buffer[0] == 'p' && buffer[1] == 'b' && buffer[2] == '\n')
		pb_b(s);
	else
		ft_error();
}

void	do_instrac(t_stacks *s, char *buffer, int readed)
{
	s->check_size = s->top_a;
	s->i = 0;
	if (buffer[0] == 'r' && buffer[1] == 'r' && buffer[2] == 'r'
		&& buffer[3] == '\n')
		rrr_b(s);
	else if (buffer[0] == 'r' && buffer[1] == 'r' && buffer[2] == 'a'
		&& buffer[3] == '\n')
		rra_b(s);
	else if (buffer[0] == 'r' && buffer[1] == 'r' && buffer[2] == 'b'
		&& buffer[3] == '\n')
		rrb_b(s);
	else if (readed)
		readed_check(buffer, s);
}

void	ok_ko(char c, t_stacks *s)
{
	if (c == 'o')
		write(1, "OK\n", 3);
	else if (c == 'k')
		write(1, "KO\n", 3);
	free(s->a);
	free(s->b);
	exit(0);
}

int	main(int ac, char **av)
{
	char		buffer[5];
	t_stacks	s;
	char		buf;

	if (ac > 1)
	{
		fill_stack(ac, av, &s);
		while (s.readed)
		{
			s.readed = read(0, &buf, 1);
			buffer[s.i++] = buf;
			if (buf == '\n')
			{
				buffer[s.i] = '\0';
				do_instrac(&s, buffer, s.readed);
			}
		}
		if (sorted_or_not(&s) && s.top_b == -1)
			ok_ko('o', &s);
		else if (!sorted_or_not(&s) || s.top_b != -1)
			ok_ko('k', &s);
	}
	return (0);
}
