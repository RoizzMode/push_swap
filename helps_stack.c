/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helps_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 12:29:38 by lschambe          #+#    #+#             */
/*   Updated: 2019/03/29 20:53:57 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_med(t_stack *a, int qua, int i, int j)
{
	int		less;
	int		bigger;
	t_stack	*head;
	t_stack	*curr;

	head = a;
	while (a && ++i < qua)
	{
		curr = head;
		j = -1;
		bigger = 0;
		less = 0;
		while (curr && ++j < qua)
		{
			if (curr->n > a->n)
				bigger++;
			if (curr->n < a->n)
				less++;
			curr = curr->next;
		}
		if (bigger == less || bigger + 1 == less || bigger - 1 == less)
			return (a->n);
		a = a->next;
	}
	return (head->n);
}

int		help_qua_not_sorted(t_stack *a, t_stack *temp, int qua, int pos)
{
	int len;

	len = 0;
	while (temp)
	{
		if (qua == -1)
			qua = pos;
		if (len < pos && a->n < temp->n)
		{
			qua = -1;
			break ;
		}
		else if (len > pos && a->n > temp->n)
		{
			qua = -1;
			break ;
		}
		len++;
		temp = temp->next;
	}
	return (qua);
}

int		qua_not_sorted(t_stack *a, int qua, int pos)
{
	t_stack	*temp;
	t_stack	*head;
	int		len;

	head = a;
	while (a)
	{
		temp = head;
		len = 0;
		qua = help_qua_not_sorted(a, temp, qua, pos);
		a = a->next;
		pos++;
	}
	return (qua);
}

int		check_stack(t_stack *a)
{
	if (!a)
		return (0);
	while (a->next)
	{
		if (a->n > a->next->n)
			return (0);
		a = a->next;
	}
	return (1);
}

int		stack_len(t_stack *a)
{
	int i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}
