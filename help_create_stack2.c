/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_create_stack2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:46:57 by lschambe          #+#    #+#             */
/*   Updated: 2019/04/03 14:47:41 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	help_sort2(t_stack **a, t_stack **b, int len)
{
	if (!check_stack(*a) && stack_len(*a) > 3)
		sort_3(a);
	if (!check_stack(*a) && stack_len(*a) <= 3)
	{
		if (len == 3)
			sort_only_3(a);
		else
			sa(a);
	}
	while (!check_stack(*a))
		sort_stack(a, b);
}

void	help_sort3(t_stack **a, t_stack **b, int len, int count)
{
	int i;

	if (!check_stack(*a) && len <= 3)
	{
		if (len == 3)
			sort_only_3(a);
		else
			sa(a);
	}
	if (check_stack(*a))
	{
		if (*b && stack_len(*b) <= 3)
			sort_3_b(b);
		i = 0;
		while (i < count)
		{
			ft_putstr("pa\n");
			push_st(a, b);
			i++;
		}
		sort_3(a);
	}
}
