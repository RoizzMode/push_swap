/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:10:06 by lschambe          #+#    #+#             */
/*   Updated: 2019/04/03 15:19:50 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include "libft/libft.h"
# include <fcntl.h>

typedef struct	s_stack
{
	int				n;
	struct s_stack	*next;
}				t_stack;

void			stackadd(t_stack **alst, t_stack *ne);
t_stack			*stacknew(int num);
void			print_stack(t_stack *a);
int				make_stack(int argc, char **argv);
int				main(int argc, char **argv);
void			swap_st(t_stack **st);
void			push_st(t_stack **a, t_stack **b);
void			rotate_st(t_stack **st);
void			reverse_rotate_st(t_stack **st);
void			sort_stack(t_stack **a, t_stack **b);
int				stack_len(t_stack *a);
int				check_stack(t_stack *a);
int				find_max(t_stack *a);
int				find_min(t_stack *a);
int				find_mid(t_stack *a, int qua);
int				stack_len(t_stack *a);
void			sort_3(t_stack **a);
int				qua_not_sorted(t_stack *a, int qua, int pos);
void			sort_only_3(t_stack **a);
int				find_med(t_stack *a, int qua, int i, int j);
void			sort_3_b(t_stack **b);
int				check_argv(char **argv, int i);
int				check_list(t_stack *a);
void			free_list(t_stack **a);
int				pb(t_stack **a, t_stack **b);
int				ra(t_stack **a);
void			rra(t_stack **a, int ra_counter);
int				help_sort(t_stack **a, t_stack **b, int not_sorted, int mid);
void			sa(t_stack **a);
void			help_sort2(t_stack **a, t_stack **b, int len);
void			help_sort3(t_stack **a, t_stack **b, int len, int count);
int				help_execute(char *c, t_stack **a, t_stack **b);
int				help_execute2(char *c, t_stack **a, t_stack **b);
int				execute(char *c, t_stack **a, t_stack **b);

#endif
