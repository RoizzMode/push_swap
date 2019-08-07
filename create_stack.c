/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:04:20 by lschambe          #+#    #+#             */
/*   Updated: 2019/04/03 14:47:44 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <fcntl.h>

void	sort_stack(t_stack **a, t_stack **b)
{
	int i;
	int len;
	int mid;
	int count;
	int not_sorted;

	count = 0;
	len = stack_len(*a);
	not_sorted = qua_not_sorted(*a, 0, 0);
	if (not_sorted == -1)
		not_sorted = stack_len(*a);
	mid = find_med(*a, not_sorted, -1, 0);
	i = 0;
	if (!(*b) && check_stack(*a))
		return ;
	if (!check_stack(*a) && len > 3)
	{
		count = help_sort(a, b, not_sorted, mid);
		help_sort2(a, b, len);
	}
	help_sort3(a, b, len, count);
	return ;
}

int		help_make_stack(char **mas, int j, t_stack **a)
{
	int			i;
	t_stack		*b;

	i = j;
	while (mas[i])
	{
		if (i == j)
		{
			if (!((*a) = stacknew(ft_atoi(mas[i++]))))
				return (0);
		}
		else
		{
			if (!(b = stacknew(ft_atoi(mas[i++]))))
			{
				free_list(a);
				return (0);
			}
			stackadd(a, b);
		}
	}
	return (1);
}

int		help_make_stack2(t_stack **a, t_stack **b)
{
	if (!check_list(*a))
	{
		free_list(a);
		return (0);
	}
	*b = NULL;
	while (!check_stack(*a))
		sort_stack(a, b);
	free_list(a);
	return (1);
}

int		make_stack(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			j;
	char		**mas;

	if (argc == 2)
	{
		mas = ft_strsplit(argv[1], ' ');
		if (!check_argv(mas, 0))
			return (0);
		j = 0;
	}
	else
	{
		mas = argv;
		if (!check_argv(argv, 1))
			return (0);
		j = 1;
	}
	if (!help_make_stack(mas, j, &a))
		return (0);
	if (!help_make_stack2(&a, &b))
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!make_stack(argc, argv))
		ft_putstr("Error\n");
	return (0);
}
