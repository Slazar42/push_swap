/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:05:35 by slazar            #+#    #+#             */
/*   Updated: 2023/05/20 23:49:40 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void readed_check(char *buffer,t_stacks *s)
{
	if (buffer[0] == 'r' && buffer[1] == 'r')
		rr_b(s);
	else if (buffer[0] == 'r' && buffer[1] == 'a')
		ra_b(s);
	else if (buffer[0] == 'r' && buffer[1] == 'b')
		rb_b(s);
	else if (buffer[0] == 's' && buffer[1] == 'a')
		sa_b(s);
	else if (buffer[0] == 's' && buffer[1] == 'b')
		sb_b(s);
	else if (buffer[0] == 's' && buffer[1] == 's')
		ss_b(s);
	else if (buffer[0] == 'p' && buffer[1] == 'a')
		pa_b(s);
	else if (buffer[0] == 'p' && buffer[1] == 'b')
		pb_b(s);
	else
		ft_error();
}
void  do_instrac(t_stacks *s, char *buffer, int readed, int *i)
{
	s->check_size = s->top_a;	
	i = 0;
	if (buffer[0] == 'r' && buffer[1] == 'r' && buffer[2] == 'r')
		rrr_b(s);
	else if (buffer[0] == 'r' && buffer[1] == 'r' && buffer[2] == 'a')
		rra_b(s);
	else if (buffer[0] == 'r' && buffer[1] == 'r' && buffer[2] == 'b')
		rrb_b(s);
	else if (readed)
		readed_check(buffer,s);
	}

int main(int ac,char **av)
{
	char	*buffer;
	t_stacks s;
	int 	readed = 1;
	char	buf;
	int 	i = 0;

	if (ac > 1)
	{
		fill_stack(ac,av,&s);
		buffer = malloc(sizeof(char) * 4);
		while (readed)
		{
			readed = read(0,&buf,1);
			buffer[i] = buf;
			i++;
			if (buf == '\n')
				do_instrac(&s,buffer,readed,&i);
		}	
		if (s.check_size != s.top_a)
			write(1,"KO\n",3);
		if(sorted_or_not(&s) && s.check_size == s.top_a)
			write(1,"OK\n",3);
		else if(!sorted_or_not(&s) && s.check_size == s.top_a)
			write(1,"KO\n",3);
		return (0);
	}
}
