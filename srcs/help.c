/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:57:45 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/09/18 14:57:49 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_1(t_out *ret)
{
	int		i;

	i = 0;
	while (ret)
	{
		if (ret->num == NOTHING)
		{
			break ;
		}
		printelement2(ret->num);
		ret = ret->nx;
		i++;
	}
}

void	ft_print_2(t_stack **sa, t_stack **sb, t_op *oplist, int debug)
{
	t_op	*begin;

	begin = oplist;
	if (!(begin->call))
		return ;
	if (debug > 0)
	{
		ft_putstr_fd("YOU ARE IN DEBUG MODE\n", 2);
		op_debug(oplist);
		stacks_debug(*sa, *sb);
	}
	while (begin)
	{
		begin->call(sa, sb);
		if (debug > 0)
		{
			printelement(begin->op);
			stacks_debug(*sa, *sb);
		}
		begin = begin->next;
	}
}

void	ft_free(t_stack **sa, t_stack **sb, t_out **ret)
{
	t_stack	*nx;
	t_out	*nxo;

	nxo = *ret;
	nx = *sa;
	while (nx)
	{
		nx = (*sa)->nx;
		free(*sa);
		*sa = nx;
	}
	nx = *sb;
	while (nx)
	{
		nx = (*sb)->nx;
		free(*sb);
		*sb = nx;
	}
	while (nxo)
	{
		nxo = (*ret)->nx;
		free(*ret);
		*ret = nxo;
	}
}
