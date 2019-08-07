/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:18:22 by lschambe          #+#    #+#             */
/*   Updated: 2019/04/03 15:38:50 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		help_check_stack(char **mas, int j, t_stack **a)
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

int		help_check_stack2(t_stack **a, t_stack **b)
{
	int		i;
	int		ret;
	char	buf[5];
	char	tmp;

	ret = 1;
	while (ret)
	{
		i = 0;
		while (i < 5 && ret)
		{
			ret = read(0, &tmp, 1);
			buf[i++] = tmp;
			if (tmp == '\n')
				break ;
		}
		if (!ret)
			break ;
		if (buf[3] != '\n' && buf[2] != '\n')
			return (0);
		buf[i] = '\0';
		if (!execute(buf, a, b))
			return (0);
	}
	return (1);
}

int		help_check_stack3(t_stack **a, t_stack **b, char **mas, int j)
{
	if (!help_check_stack(mas, j, a))
		return (0);
	if (!check_list(*a))
	{
		free_list(a);
		return (0);
	}
	if (!help_check_stack2(a, b))
		return (0);
	if (check_stack(*a) && !(*b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
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
		if (!check_argv(mas, 1))
			return (0);
		j = 1;
	}
	b = NULL;
	if (!help_check_stack3(&a, &b, mas, j))
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!make_stack(argc, argv))
		ft_putstr_fd("Error\n", 2);
	return (0);
}
