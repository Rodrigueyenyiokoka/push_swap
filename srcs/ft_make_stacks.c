/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:54:06 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/09/18 14:54:09 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_valid_check(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		if (ps_big_atoi(argv[i]) > INT_MAX || ps_big_atoi(argv[i]) < INT_MIN)
			return (0);
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				;
			else if (!ft_isdigit(argv[i][j]))
			{
				if (!(argv[i][j] == '-' && ft_isdigit(argv[i][j + 1])))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_split(t_stack **stack, char *argvin)
{
	int		j;
	char	**tmp;

	j = 0;
	tmp = ft_strsplit(argvin, ' ');
	while (tmp[j])
	{
		(*stack)->v = (int)ps_big_atoi(tmp[j]);
		if (!tmp[j + 1])
			break ;
		(*stack)->nx = stack_initializer();
		((*stack)->nx)->pv = (*stack);
		(*stack) = (*stack)->nx;
		j++;
	}
	j = 0;
	while (tmp[j])
	{
		free(tmp[j]);
		j++;
	}
	free(tmp);
}

t_stack	*ft_new_stack(char **argv)
{
	int		i;
	t_stack	*stack;
	t_stack *begin;

	i = 1;
	stack = stack_initializer();
	begin = stack;
	while (argv[i])
	{
		ft_split(&stack, argv[i]);
		if (!argv[i + 1])
			return (begin);
		stack->nx = stack_initializer();
		(stack->nx)->pv = stack;
		stack = stack->nx;
		i++;
	}
	return (begin);
}

int		ft_is_duplicated(t_stack *stacka)
{
	int		nbr;
	int		flag;
	t_stack	*tmpa;
	t_stack *tmpb;

	tmpa = stacka;
	while (stacka)
	{
		nbr = stacka->v;
		flag = 0;
		tmpb = tmpa;
		while (tmpb)
		{
			if (tmpb->v == nbr)
				flag++;
			if (flag > 1)
				return (1);
			tmpb = tmpb->nx;
		}
		stacka = stacka->nx;
	}
	return (0);
}

t_stack	*ft_is_integer(int argc, char **argv, t_stack *stacka)
{
	char	**tmp;

	tmp = argv;
	if (argc < 2)
		return (NULL);
	if (!(ft_strcmp("-v", tmp[1])))
		tmp++;
	if (!ft_valid_check(tmp))
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	stacka = ft_new_stack(tmp);
	if (ft_is_duplicated(stacka))
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	return (stacka);
}
