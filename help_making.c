/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_making.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:05:09 by lschambe          #+#    #+#             */
/*   Updated: 2019/03/29 20:51:36 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		f_atoi(const char *str)
{
	int			ato;
	int			plmi;
	int			check;

	ato = 0;
	plmi = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
	|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
		plmi = -1;
	if (*str == '-' || *str == '+')
		str++;
	check = ato;
	while (*str >= '0' && *str <= '9')
	{
		ato = ato * 10 + plmi * (*str - '0');
		if (ato < check && plmi == 1)
			return (-1);
		if (ato > check && plmi == -1)
			return (0);
		check = ato;
		str++;
	}
	return (ato);
}

int		check_argv(char **argv, int i)
{
	int j;

	while (argv[i])
	{
		j = 1;
		if (!((argv[i][0] >= '0' && argv[i][0] <= '9') || argv[i][0] == '-'))
			return (0);
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (0);
			j++;
		}
		if (ft_strlen(argv[i]) > 2 && (f_atoi(argv[i]) == -1
					|| f_atoi(argv[i]) == 0))
			return (0);
		if (f_atoi(argv[i]) < -2147483648 || f_atoi(argv[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int		help_sort_3_b(t_stack **b)
{
	if (stack_len(*b) == 2 && (*b)->n < (*b)->next->n)
	{
		ft_putstr("sb\n");
		swap_st(b);
		return (1);
	}
	else if (stack_len(*b) == 3 && (*b)->n < (*b)->next->n &&
			(*b)->next->n < (*b)->next->next->n)
	{
		ft_putstr("rb\n");
		ft_putstr("sb\n");
		rotate_st(b);
		swap_st(b);
		return (1);
	}
	else if (stack_len(*b) == 3 && (*b)->n > (*b)->next->n &&
	(*b)->next->n < (*b)->next->next->n && (*b)->n < (*b)->next->next->n)
	{
		ft_putstr("rrb\n");
		reverse_rotate_st(b);
		return (1);
	}
	return (0);
}

void	sort_3_b(t_stack **b)
{
	if (help_sort_3_b(b))
		return ;
	else if (stack_len(*b) == 3 && (*b)->n > (*b)->next->n &&
	(*b)->next->n < (*b)->next->next->n && (*b)->n > (*b)->next->next->n)
	{
		ft_putstr("rrb\n");
		ft_putstr("sb\n");
		reverse_rotate_st(b);
		swap_st(b);
	}
	else if (stack_len(*b) == 3 && (*b)->n < (*b)->next->n &&
	(*b)->next->n > (*b)->next->next->n && (*b)->n > (*b)->next->next->n)
	{
		swap_st(b);
		ft_putstr("sb\n");
	}
	else if (stack_len(*b) == 3 && (*b)->n < (*b)->next->n &&
	(*b)->next->n > (*b)->next->next->n && (*b)->n > (*b)->next->next->n)
	{
		ft_putstr("rb\n");
		rotate_st(b);
	}
}
