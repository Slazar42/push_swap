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
}	t_stacks;

void sort_3(t_stacks *s);
void sort_5(t_stacks *s);
int		smallest(t_stacks *s,int n);
int 	biggest(t_stacks *s,int n);
char    *ft_substr(char *s, unsigned int start, int len);
// int     ft_atoi(char *str);
char	*ft_strdup(char *s1);
int *sorted_arr(int *arr,int top);
int		smallest(t_stacks *s,int n);
char	*ft_calloc(int count, int size);
// char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *c);
// void	swap_a_sa(t_stacks *st);
// void	swap_b_sb(t_stacks *st);
// void	swap_a_b_ss(t_stacks *st);
// void	push_a_pa(t_stacks *st);
// void	push_b_pb(t_stacks	*st);
// void	rotate_a_ra(t_stacks *st);
// void	rotate_b_rb(t_stacks *st);
// void	rotate_a_b_rr(t_stacks *st);
// void	reverse_rotate_a_rra(t_stacks *st);
// void	reverse_rotate_b_rrb(t_stacks *st);
// void	reverse_rotate_a_b_rrr(t_stacks *st);
void	ra(t_stacks *st);
void	pa(t_stacks *st);
void	sa(t_stacks *st);
void	rr(t_stacks *st);
void	rrr(t_stacks *st);
void	sb(t_stacks *st);
int	biggest(t_stacks *st,int n);


#endif