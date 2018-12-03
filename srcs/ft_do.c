/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:19:31 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/09/18 14:49:39 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		find_smallest(t_stack *sb)
{
	int		smallest;
	t_stack	*tmp;

	tmp = sb;
	smallest = tmp->v;
	while (tmp)
	{
		if (smallest > tmp->v)
			smallest = tmp->v;
		tmp = tmp->nx;
	}
	return (smallest);
}

int		find_lagest(t_stack *sb)
{
	int		largest;
	t_stack	*tmp;

	tmp = sb;
	largest = tmp->v;
	while (tmp)
	{
		if (largest < tmp->v)
			largest = tmp->v;
		tmp = tmp->nx;
	}
	return (largest);
}

void	ft_do_op(t_onum num, t_stack **sa, t_stack **sb)
{
	if (num == SA)
		sa_op(sa, sb);
	else if (num == SB)
		sb_op(sa, sb);
	else if (num == SS)
		ss_op(sa, sb);
	else if (num == PA)
		pa_op(sa, sb);
	else if (num == PB)
		pb_op(sa, sb);
	else if (num == RA)
		ra_op(sa, sb);
	else if (num == RB)
		rb_op(sa, sb);
	else if (num == RR)
		rr_op(sa, sb);
	else if (num == RRA)
		rra_op(sa, sb);
	else if (num == RRB)
		rrb_op(sa, sb);
	else if (num == RRR)
		rrr_op(sa, sb);
}
