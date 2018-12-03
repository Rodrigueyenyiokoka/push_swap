/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:52:28 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/09/18 16:33:50 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int argc, char **argv)
{
	t_op	*oplist;
	t_stack	*stacka;
	t_stack *stackb;
	int		tmp;

	tmp = 0;
	stacka = NULL;
	stackb = NULL;
	if (!(stacka = ft_is_integer(argc, argv, stacka)))
		return (0);
	oplist = get_next_op();
	if (!(ft_strcmp("-v", argv[1])))
		tmp = 1;
	ft_print_2(&stacka, &stackb, oplist, tmp);
	if ((tmp = ft_is_ordered(stacka, stackb)))
	{
		if (tmp == 1)
			ft_putstr("OK\n");
		else
			write(2, "Error\n", 6);
	}
	else
		ft_putstr("KO\n");
	return (0);
}
