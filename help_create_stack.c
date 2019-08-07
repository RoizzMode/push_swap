/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_create_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:45:02 by lschambe          #+#    #+#             */
/*   Updated: 2019/04/03 14:46:22 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pb(t_stack **a, t_stack **b)
{
	ft_putstr("pb\n");
	push_st(b, a);
	return (1);
}

int		ra(t_stack **a)
{
	ft_putstr("ra\n");
	rotate_st(a);
	return (1);
}

void	rra(t_stack **a, int ra_counter)
{
	int j;

	j = 0;
	while (j < ra_counter)
	{
		ft_putstr("rra\n");
		reverse_rotate_st(a);
		j++;
	}
}

int		help_sort(t_stack **a, t_stack **b, int not_sorted, int mid)
{
	int i;
	int count;
	int len;
	int ra_counter;

	len = stack_len(*a);
	ra_counter = 0;
	i = 0;
	count = 0;
	while (i < len)
	{
		if ((*a)->n < mid && i < not_sorted)
			count += pb(a, b);
		else if ((*a)->n >= mid && i < not_sorted)
			ra_counter += ra(a);
		else if (i > not_sorted && not_sorted < (len / 2))
		{
			rra(a, ra_counter);
			break ;
		}
		else if (i >= not_sorted)
			ra_counter += ra(a);
		i++;
	}
	return (count);
}

void	sa(t_stack **a)
{
	ft_putstr("sa\n");
	swap_st(a);
}
