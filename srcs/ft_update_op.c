/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:57:13 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/09/18 14:57:19 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op4(t_stack *target, t_stack **sa, t_stack **sb, t_out *ret)
{
	int a;
	int b;

	a = target->mar;
	b = target->mbf;
	if (b > 0 & a > 0)
	{
		op(ret, RRA, sa, sb);
		op(ret, RB, sa, sb);
	}
	else if (b > 0)
		op(ret, RB, sa, sb);
	else if (a > 0)
		op(ret, RRA, sa, sb);
	target->mar -= 1;
	target->mbf -= 1;
}

void	op3(t_stack *target, t_stack **sa, t_stack **sb, t_out *ret)
{
	int a;
	int b;

	a = target->maf;
	b = target->mbr;
	if (b > 0 & a > 0)
	{
		op(ret, RA, sa, sb);
		op(ret, RRB, sa, sb);
	}
	else if (b > 0)
		op(ret, RRB, sa, sb);
	else if (a > 0)
		op(ret, RA, sa, sb);
	target->maf -= 1;
	target->mbr -= 1;
}

void	op2(t_stack *target, t_stack **sa, t_stack **sb, t_out *ret)
{
	int a;
	int b;

	a = target->mar;
	b = target->mbr;
	if (b > 0 & a > 0)
		op(ret, RRR, sa, sb);
	else if (b > 0)
		op(ret, RRB, sa, sb);
	else if (a > 0)
		op(ret, RRA, sa, sb);
	target->mar -= 1;
	target->mbr -= 1;
}

void	op1(t_stack *target, t_stack **sa, t_stack **sb, t_out *ret)
{
	int a;
	int b;

	a = target->maf;
	b = target->mbf;
	if (b > 0 & a > 0)
		op(ret, RR, sa, sb);
	else if (b > 0)
		op(ret, RB, sa, sb);
	else if (a > 0)
		op(ret, RA, sa, sb);
	target->maf -= 1;
	target->mbf -= 1;
}

void	op_updating(t_stack *target, t_stack **sa, t_stack **sb, t_out *ret)
{
	int		moves;

	moves = target->moves;
	while (moves)
	{
		if (target->dir == 1)
			op1(target, sa, sb, ret);
		else if (target->dir == 2)
			op2(target, sa, sb, ret);
		else if (target->dir == 3)
			op3(target, sa, sb, ret);
		else if (target->dir == 4)
			op4(target, sa, sb, ret);
		if (ft_ordered(*sa))
			return ;
		moves--;
	}
}
