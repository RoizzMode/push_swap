/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_making.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 18:56:24 by lschambe          #+#    #+#             */
/*   Updated: 2019/03/29 20:49:14 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stackadd(t_stack **alst, t_stack *ne)
{
	t_stack *temp;

	temp = *alst;
	while (temp->next)
		temp = temp->next;
	temp->next = ne;
}

t_stack	*stacknew(int num)
{
	t_stack *st;

	st = (t_stack*)malloc(sizeof(t_stack));
	if (!st)
		return (NULL);
	st->n = num;
	st->next = NULL;
	return (st);
}

void	print_stack(t_stack *a)
{
	while (a)
	{
		printf("%d\n", a->n);
		a = a->next;
	}
	printf("\n");
}

int		check_list(t_stack *a)
{
	t_stack	*head;
	t_stack	*temp;
	int		counter;

	head = a;
	while (a)
	{
		temp = head;
		counter = 0;
		while (temp)
		{
			if (a->n == temp->n)
				counter++;
			temp = temp->next;
		}
		if (counter > 1)
			return (0);
		a = a->next;
	}
	return (1);
}

void	free_list(t_stack **a)
{
	t_stack *temp;

	while ((*a))
	{
		temp = *a;
		(*a) = (*a)->next;
		free(temp);
	}
}
