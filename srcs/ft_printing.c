/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:55:22 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/09/18 14:55:26 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	printer_help(t_stack *tmpa, t_stack *tmpb)
{
	if (tmpa && tmpb)
	{
		ft_putnbr_fd((tmpa)->v, 2);
		ft_putstr_fd("\t", 2);
		ft_putnbr_fd((tmpb)->v, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (tmpa)
	{
		ft_putnbr_fd((tmpa)->v, 2);
		ft_putstr_fd("\t", 2);
		ft_putstr_fd("\n", 2);
	}
	else if (tmpb)
	{
		ft_putstr_fd("\t\t", 2);
		ft_putnbr_fd(tmpb->v, 2);
		ft_putstr_fd("\n", 2);
	}
}

void	stacks_debug(t_stack *stacka, t_stack *stackb)
{
	t_stack *tmpa;
	t_stack *tmpb;

	tmpa = stacka;
	tmpb = stackb;
	ft_putstr_fd("stack A\tstack BB\n", 2);
	while (tmpa || tmpb)
	{
		printer_help(tmpa, tmpb);
		if (tmpa && tmpb)
		{
			tmpa = (tmpa)->nx;
			tmpb = (tmpb)->nx;
		}
		else if (tmpa)
			tmpa = (tmpa)->nx;
		else if (tmpb)
			tmpb = (tmpb)->nx;
	}
}

int		op_debug(t_op *begin)
{
	int i;

	i = 0;
	while (begin)
	{
		if (begin->op == nothing)
		{
			break ;
		}
		i++;
		printelement(begin->op);
		begin = begin->next;
	}
	ft_putstr_fd("Total number of Ops is:", 2);
	ft_putnbr_fd(i, 2);
	ft_putstr_fd("\n", 2);
	return (i);
}

void	printelement(t_optype num)
{
	if (num == sa)
		ft_putstr_fd("sa\n", 2);
	else if (num == sb)
		ft_putstr_fd("sb\n", 2);
	else if (num == ss)
		ft_putstr_fd("ss\n", 2);
	else if (num == pa)
		ft_putstr_fd("pa\n", 2);
	else if (num == pb)
		ft_putstr_fd("pb\n", 2);
	else if (num == ra)
		ft_putstr_fd("ra\n", 2);
	else if (num == rb)
		ft_putstr_fd("rb\n", 2);
	else if (num == rr)
		ft_putstr_fd("rr\n", 2);
	else if (num == rra)
		ft_putstr_fd("rra\n", 2);
	else if (num == rrb)
		ft_putstr_fd("rrb\n", 2);
	else if (num == rrr)
		ft_putstr_fd("rrr\n", 2);
}

void	printelement2(t_onum num)
{
	if (num == SA)
		ft_putstr("sa\n");
	else if (num == SB)
		ft_putstr("sb\n");
	else if (num == SS)
		ft_putstr("ss\n");
	else if (num == PA)
		ft_putstr("pa\n");
	else if (num == PB)
		ft_putstr("pb\n");
	else if (num == RA)
		ft_putstr("ra\n");
	else if (num == RB)
		ft_putstr("rb\n");
	else if (num == RR)
		ft_putstr("rr\n");
	else if (num == RRA)
		ft_putstr("rra\n");
	else if (num == RRB)
		ft_putstr("rrb\n");
	else if (num == RRR)
		ft_putstr("rrr\n");
	else if (num == NOTHING)
		ft_putstr("\n");
}
