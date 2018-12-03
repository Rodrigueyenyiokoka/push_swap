/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:54:52 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/09/18 14:54:56 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_ordered(t_stack *stackb)
{
	int		tmp;

	if (!(stackb))
		return (0);
	tmp = stackb->v;
	while (stackb->nx)
	{
		if ((stackb->nx)->v > tmp)
			tmp = (stackb->nx)->v;
		else if ((stackb->nx)->v == tmp)
			return (2);
		else
			return (0);
		stackb = stackb->nx;
	}
	return (1);
}

int		ft_half_ordered(t_stack *stackb)
{
	int tmp;
	int tmp2;

	if (!(stackb))
		return (1);
	if (ft_ordered(stackb))
		return (1);
	tmp = stackb->v;
	tmp2 = stackb->v;
	if (ft_half_ordered_2(stackb, tmp, tmp2))
		return (1);
	else
		return (0);
	return (0);
}

int		ft_half_ordered_2(t_stack *stackb, int tmp, int tmp2)
{
	int flag;

	flag = 0;
	while (stackb)
	{
		if (!(stackb->nx))
			break ;
		if ((stackb->nx)->v > tmp)
			tmp = (stackb->nx)->v;
		else if ((stackb->nx)->v == tmp)
			return (1);
		else if (flag == 0)
			flag++;
		else
			return (0);
		stackb = stackb->nx;
	}
	if (flag == 1 && stackb->v < tmp2)
		return (1);
	return (0);
}

int		ft_is_ordered(t_stack *stacka, t_stack *stackb)
{
	int		tmp;

	if (stackb)
		return (0);
	else if (!(stacka))
		return (0);
	tmp = stacka->v;
	while (stacka->nx)
	{
		if ((stacka->nx)->v > tmp)
			tmp = (stacka->nx)->v;
		else if ((stacka->nx)->v == tmp)
			return (2);
		else
			return (0);
		stacka = stacka->nx;
	}
	return (1);
}
