/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_stack_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:52:52 by lschambe          #+#    #+#             */
/*   Updated: 2019/03/29 20:53:46 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	help_sort_only_3(t_stack **a)
{
	if ((*a)->n > (*a)->next->n && (*a)->next->n > (*a)->next->next->n)
	{
		ft_putstr("ra\n");
		ft_putstr("sa\n");
		rotate_st(a);
		swap_st(a);
	}
	if ((*a)->n < (*a)->next->n && (*a)->next->n
			> (*a)->next->next->n && (*a)->n > (*a)->next->next->n)
	{
		ft_putstr("rra\n");
		reverse_rotate_st(a);
	}
	if ((*a)->n < (*a)->next->n && (*a)->next->n
			> (*a)->next->next->n && (*a)->n < (*a)->next->next->n)
	{
		ft_putstr("rra\n");
		ft_putstr("sa\n");
		reverse_rotate_st(a);
		swap_st(a);
	}
}

void	sort_only_3(t_stack **a)
{
	help_sort_only_3(a);
	if ((*a)->n > (*a)->next->n && (*a)->next->n
			< (*a)->next->next->n && (*a)->n < (*a)->next->next->n)
	{
		swap_st(a);
		ft_putstr("sa\n");
	}
	if ((*a)->n > (*a)->next->n && (*a)->next->n
			< (*a)->next->next->n && (*a)->n > (*a)->next->next->n)
	{
		ft_putstr("ra\n");
		rotate_st(a);
	}
}

void	help_sort_3(t_stack **a)
{
	if ((*a)->n > (*a)->next->n && (*a)->next->n > (*a)->next->next->n)
	{
		ft_putstr("sa\n");
		ft_putstr("ra\n");
		ft_putstr("sa\n");
		ft_putstr("rra\n");
		ft_putstr("sa\n");
		swap_st(a);
		rotate_st(a);
		swap_st(a);
		reverse_rotate_st(a);
		swap_st(a);
	}
	if ((*a)->n < (*a)->next->n && (*a)->next->n
			> (*a)->next->next->n && (*a)->n > (*a)->next->next->n)
	{
		ft_putstr("ra\n");
		ft_putstr("sa\n");
		ft_putstr("rra\n");
		rotate_st(a);
		swap_st(a);
		reverse_rotate_st(a);
	}
}

void	help_2_sort_3(t_stack **a)
{
	if ((*a)->n < (*a)->next->n && (*a)->next->n
			> (*a)->next->next->n && (*a)->n < (*a)->next->next->n)
	{
		ft_putstr("ra\n");
		ft_putstr("sa\n");
		ft_putstr("rra\n");
		rotate_st(a);
		swap_st(a);
		reverse_rotate_st(a);
	}
	if ((*a)->n > (*a)->next->n && (*a)->next->n
			< (*a)->next->next->n && (*a)->n < (*a)->next->next->n)
	{
		ft_putstr("sa\n");
		swap_st(a);
	}
}

void	sort_3(t_stack **a)
{
	if (stack_len(*a) < 3)
		return ;
	help_sort_3(a);
	help_2_sort_3(a);
	if ((*a)->n > (*a)->next->n && (*a)->next->n
			< (*a)->next->next->n && (*a)->n > (*a)->next->next->n)
	{
		ft_putstr("sa\n");
		ft_putstr("ra\n");
		ft_putstr("sa\n");
		ft_putstr("rra\n");
		swap_st(a);
		rotate_st(a);
		swap_st(a);
		reverse_rotate_st(a);
	}
}
