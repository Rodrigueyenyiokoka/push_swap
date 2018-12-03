/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotation_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:56:24 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/09/18 14:56:30 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra_op(t_stack **stacka, t_stack **stackb)
{
	t_stack *tmpb;
	t_stack *tmpa;

	tmpb = *stackb;
	tmpa = *stacka;
	if (*stacka && (*stacka)->nx)
	{
		while (tmpa->nx)
		{
			tmpa = tmpa->nx;
		}
		tmpa->nx = *stacka;
		(tmpa->pv)->nx = NULL;
		(*stacka)->pv = tmpa;
		(*stacka) = tmpa;
		(*stacka)->pv = NULL;
	}
}

void	rrb_op(t_stack **stacka, t_stack **stackb)
{
	t_stack *tmpb;
	t_stack *tmpa;

	tmpb = *stackb;
	tmpa = *stacka;
	if (*stackb && (*stackb)->nx)
	{
		while (tmpb->nx)
			tmpb = tmpb->nx;
		tmpb->nx = *stackb;
		(tmpb->pv)->nx = NULL;
		(*stackb)->pv = tmpb;
		(*stackb) = tmpb;
		(*stackb)->pv = NULL;
	}
}

void	rrr_op(t_stack **stacka, t_stack **stackb)
{
	rra_op(stacka, stackb);
	rrb_op(stacka, stackb);
}

void	ft_rot(t_out *ret, t_stack **sa, t_stack **sb, int descending)
{
	int		tmp;

	tmp = 0;
	if (descending)
	{
		tmp = find_lagest(*sb);
		if (ft_position(*sb, tmp) >= 0)
			while ((*sb)->v != tmp)
				op(ret, RB, sa, sb);
		else
			while ((*sb)->v != tmp)
				op(ret, RRB, sa, sb);
	}
	else
	{
		tmp = find_smallest(*sa);
		if (ft_position(*sa, tmp) >= 0)
			while ((*sa)->v != tmp)
				op(ret, RA, sa, sb);
		else
			while ((*sa)->v != tmp)
				op(ret, RRA, sa, sb);
	}
}
