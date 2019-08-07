/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:36:35 by lschambe          #+#    #+#             */
/*   Updated: 2019/03/29 15:47:14 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_st(t_stack **st)
{
	t_stack *temp;

	if (!(*st) || !(*st)->next)
		return ;
	temp = (*st)->next;
	(*st)->next = (*st)->next->next;
	temp->next = *st;
	*st = temp;
	return ;
}

void	push_st(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (!(*b))
		return ;
	temp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	(*b) = temp;
}

void	rotate_st(t_stack **st)
{
	t_stack *temp;
	t_stack *temp2;

	if (!(*st) || !(*st)->next)
		return ;
	temp2 = (*st)->next;
	temp = *st;
	while (temp->next)
		temp = temp->next;
	temp->next = (*st);
	(*st)->next = NULL;
	(*st) = temp2;
}

void	reverse_rotate_st(t_stack **st)
{
	t_stack *temp;
	t_stack *temp2;

	if (!(*st) || !(*st)->next)
		return ;
	temp = *st;
	while (temp->next->next)
		temp = temp->next;
	temp2 = temp->next;
	temp2->next = *st;
	*st = temp2;
	temp->next = NULL;
}
