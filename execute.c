/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:09:22 by lschambe          #+#    #+#             */
/*   Updated: 2019/04/03 15:10:27 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		help_execute(char *c, t_stack **a, t_stack **b)
{
	if (ft_strlen(c) < 2)
		return (0);
	else if (c[0] == 's' && c[1] == 'a' && c[2] == '\n')
		swap_st(a);
	else if (c[0] == 's' && c[1] == 'b' && c[2] == '\n')
		swap_st(b);
	else if (c[0] == 's' && c[1] == 's' && c[2] == '\n')
	{
		swap_st(a);
		swap_st(b);
	}
	else
		return (0);
	return (1);
}

int		help_execute2(char *c, t_stack **a, t_stack **b)
{
	if (ft_strlen(c) < 2)
		return (0);
	else if (c[0] == 'r' && c[1] == 'a' && c[2] == '\n')
		rotate_st(a);
	else if (c[0] == 'r' && c[1] == 'b' && c[2] == '\n')
		rotate_st(b);
	else if (c[0] == 'r' && c[1] == 'r' && c[2] == '\n')
	{
		rotate_st(a);
		rotate_st(b);
	}
	else if (c[0] == 'r' && c[1] == 'r' && c[2] == 'a' && c[3] == '\n')
		reverse_rotate_st(a);
	else if (c[0] == 'r' && c[1] == 'r' && c[2] == 'b' && c[3] == '\n')
		reverse_rotate_st(b);
	else if (c[0] == 'r' && c[1] == 'r' && c[2] == 'r' && c[3] == '\n')
	{
		reverse_rotate_st(a);
		reverse_rotate_st(b);
	}
	else
		return (0);
	return (1);
}

int		execute(char *c, t_stack **a, t_stack **b)
{
	if (c[0] == 's')
	{
		if (!help_execute(c, a, b))
			return (0);
	}
	else if (c[0] == 'p' && c[1] == 'a' && c[2] == '\n')
		push_st(a, b);
	else if (c[0] == 'p' && c[1] == 'b' && c[2] == '\n')
		push_st(b, a);
	else if (c[0] == 'r')
	{
		if (!help_execute2(c, a, b))
			return (0);
	}
	else
		return (0);
	return (1);
}
