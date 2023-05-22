#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

typedef struct stacks
{
	int	*a;
	int	*b;
	int	top_a;
	int	top_b;
	int check_size;
	int readed;
	int i;
}	t_stacks;

void sort_3(t_stacks *s);
void sort_5(t_stacks *s);
void ft_error();
char    *ft_substr(char *s, unsigned int start, int len);
char	*ft_strdup(char *s1);
int *sorted_arr(int *arr,int top);
char	*ft_calloc(int count, int size);
char	*ft_strjoin(char *s1, char *s2);
void do_instrac(t_stacks *s, char *buffer, int readed);
int		ft_strlen(char *c);
int sorted_or_not(t_stacks *s);
void	ft_check(char *str,int *n);
void *ft_atoiin(char *str,int *arr,int n);
void fill_stack(int ac,char **av,t_stacks *s);
void	ra(t_stacks *st);
void	pa(t_stacks *st);
void	sa(t_stacks *st);
void	rra(t_stacks *st);
void	rr(t_stacks *st);
void	rb(t_stacks *st);
void	ss(t_stacks *st);
void	rrb(t_stacks *st);
void	pb(t_stacks *st);
void	rrr(t_stacks *st);
void	sb(t_stacks *st);
void	ra_b(t_stacks *st);
void	pa_b(t_stacks *st);
void	sa_b(t_stacks *st);
void	rra_b(t_stacks *st);
void	rr_b(t_stacks *st);
void	rb_b(t_stacks *st);
void	rrb_b(t_stacks *st);
void	pb_b(t_stacks *st);
void	rrr_b(t_stacks *st);
void	sb_b(t_stacks *st);
void	ss_b(t_stacks *st);
int		biggest(int *a,int top);
int		smallest(int *a,int top);

#endif