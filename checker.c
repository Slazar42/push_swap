/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:05:35 by slazar            #+#    #+#             */
/*   Updated: 2023/05/24 01:56:17 by slazar           ###   ########.fr       */
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
void  do_instrac(t_stacks *s, char *buffer, int readed)
{
	if (buffer[0] == 'r' && buffer[1] == 'r' && buffer[2] == 'r')
		rrr_b(s);
	else if (buffer[0] == 'r' && buffer[1] == 'r' && buffer[2] == 'a')
		rra_b(s);
	else if ( buffer[0] == 'r' && buffer[1] == 'r' && buffer[2] == 'b')
		rrb_b(s);
	else if (readed)
		readed_check(buffer,s);
	}

void ok_ko(char c,t_stacks *s)
{
	if (c == 'k')
	{
		write(1,"KO\n",3);
		// free(s->a);
		// free(s->b);
	}
	else if (c == 'o')
	{
		write(1,"OK\n",3);
		// free(s->a);
		// free(s->b);
	}
}
int main(int ac,char **av)
{
	char	*buffer;
	t_stacks s;
	char	buf;
	int	old_top_a;
	if (ac > 1)
	{
		fill_stack(ac,av,&s);
		old_top_a = s.top_a;
		buffer = calloc(sizeof(char) , 4);
		// printf("a[s.top_a] = %d\n",s.a[s.top_a]);
		// rra_b(&s);
		// for(int i  = 0; i <= s.top_a;)
		// 	printf("|%d|\n",s.a[i++]);
		// exit(0);
		
		buffer[3] = '\0';
		while (s.readed)
		{
			s.readed = read(0,&buffer[s.i],1);
			// buffer[s.i++] = buf;
			
			if (buffer[s.i] == '\n')
				do_instrac(&s,buffer,s.readed);
			// else if (!(s.readed == 3 || s.readed == 4))
			// 	ft_error();
			s.i++;
		}
		free(buffer);
		// printf("top_a = %d\n",s.top_a);
		// printf("old_top_a = %d\n",old_top_a);
		if (old_top_a != s.top_a)
			ok_ko('k',&s);
		if (sorted_or_not(&s) && old_top_a == s.top_a)
			ok_ko('o',&s);
		else if(!sorted_or_not(&s) && old_top_a == s.top_a)
			ok_ko('k',&s);
		printf("a[s.top_a] = %d\n",s.a[s.top_a]);
	}
	return (0);
}