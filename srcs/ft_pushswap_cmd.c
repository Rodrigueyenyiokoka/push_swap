/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:13:16 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/09/18 14:49:33 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa_op(t_stack **stacka, t_stack **stackb)
{
	t_stack *tmpa;
	t_stack *tmpb;

	tmpb = *stackb;
	if (*stacka && (*stacka)->nx)
	{
		tmpa = (*stacka);
		(*stacka) = (*stacka)->nx;
		tmpa->nx = (*stacka)->nx;
		tmpa->pv = (*stacka);
		(*stacka)->nx = tmpa;
		(*stacka)->pv = NULL;
	}
	tmpa = *stacka;
	while (tmpa->nx)
	{
		(tmpa->nx)->pv = tmpa;
		tmpa = tmpa->nx;
	}
}

void	sb_op(t_stack **stacka, t_stack **stackb)
{
	t_stack *tmpa;
	t_stack *tmpb;

	tmpa = *stacka;
	if (*stackb && (*stackb)->nx)
	{
		tmpb = (*stackb);
		(*stackb) = (*stackb)->nx;
		tmpb->nx = (*stackb)->nx;
		tmpb->pv = (*stackb);
		(*stackb)->nx = tmpb;
		(*stackb)->pv = NULL;
	}
	tmpb = *stackb;
	while (tmpb->nx)
	{
		(tmpb->nx)->pv = tmpb;
		tmpb = tmpb->nx;
	}
}

void	pa_op(t_stack **stacka, t_stack **stackb)
{
	t_stack *tmp;

	tmp = *stackb;
	if (*stackb)
	{
		if (!(*stacka))
		{
			*stacka = *stackb;
			*stackb = (*stackb)->nx;
			(*stacka)->nx = NULL;
			(*stacka)->pv = NULL;
		}
		else
		{
			*stackb = (*stackb)->nx;
			tmp->nx = (*stacka);
			(*stacka)->pv = tmp;
			*stacka = tmp;
		}
	}
	if (*stackb)
	{
		(*stackb)->pv = NULL;
	}
}

void	pb_op(t_stack **stacka, t_stack **stackb)
{
	t_stack *tmp;

	tmp = *stacka;
	if (*stacka)
	{
		if (!(*stackb))
		{
			*stackb = *stacka;
			*stacka = (*stacka)->nx;
			(*stackb)->nx = NULL;
			(*stackb)->pv = NULL;
		}
		else
		{
			*stacka = (*stacka)->nx;
			tmp->nx = (*stackb);
			(*stackb)->pv = tmp;
			*stackb = tmp;
		}
	}
	if (*stacka)
	{
		(*stacka)->pv = NULL;
	}
}

void	ss_op(t_stack **stacka, t_stack **stackb)
{
	sa_op(stacka, stackb);
	sb_op(stacka, stackb);
}
