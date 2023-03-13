/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:31:42 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/13 17:43:17 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<limits.h>

typedef struct s_push
{
	char	*joined;
	char	**splited;
	int		*values;
	int		i;
	int		j;

}	t_push;

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		*fake;
	int		topa;
	int		topb;
	int		lena;
	int		lenb;
}	t_stack;

size_t	ft_getlen(char **av);
void	concatenateargs(char *av, char *p);
void	ft_pushswap(t_stack stack, t_push push, char **av);
int		ft_isdigit(int c);
int		check_args(char *str);
int		check_operator(char *av);
void	ft_exit(char *error);
char	*ft_joinargs(char **av);
int		ft_check(t_push push);
int		hasduplicate(char **arr, int len);
int		*init_stack(int len);
void	ss(t_stack stack);
void	ft_push(int data, int len, int *stack);
void	print_stack(int *stack, int len, int a);
void	sa(int *stack, int len, int p);
void	sb(int *stack, int len, int p);
void	pb(t_stack *stack);
void	pa(t_stack *stack);
void	ra(t_stack *stack, int p);
void	rb(t_stack *stack, int p);
void	rr(t_stack *stack);
void	rra(t_stack *stack, int p);
void	rrb(t_stack *stack, int p);
void	rrr(t_stack *stack);
int		is_sorted(int *t, int len);
void	swap(int *a, int *b);
int		*f_to_b(t_stack *stack);
void	sort_table(int *stack, int len);
void	back_to_a(t_stack *stack);
int		max_stack(int *stack, int len);
void	sort_3(t_stack *stack);
void	sort_4(t_stack *stack);
void	sort_5(t_stack *stack);
int		min_stack(int *stack, int len);
void	sort_stack(t_stack *stack);
void	s_to_v(t_push *push, int check);
void	v_to_a(t_push *push, t_stack *stack, int check);
void	check_fi_ai(t_stack *stack, int j, int index2, int index1);
void	mv_a_1(t_stack *stack);
void	mv_b_up_a_down(t_stack *stack, int i);
void	sort_2(t_stack *stack);
int		ft_atoi(const char *s);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_bzero(void *s, size_t n);
int		ft_strncmp(const char *str1, const char	*str2, size_t lenght);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif