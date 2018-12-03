/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:24:00 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/09/18 14:49:29 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_best_insertion(t_stack **sa, t_stack **sb, t_out *ret)
{
	t_stack		*tmp;
	t_stack		*target;
	int			moves;

	tmp = *sa;
	target = tmp;
	moves = tmp->moves;
	while (tmp)
	{
		if (tmp->moves < moves)
		{
			moves = tmp->moves;
			target = tmp;
		}
		tmp = tmp->nx;
	}
	op_updating(target, sa, sb, ret);
	op(ret, PB, sa, sb);
}

void	ft_merge(t_stack **sa, t_stack **sb, t_out *ret)
{
	while (*sb)
	{
		if ((*sb)->v > find_lagest(*sa))
		{
			ft_rot(ret, sa, sb, 0);
			op(ret, PA, sa, sb);
		}
		else if ((*sb)->v < find_smallest(*sa))
		{
			ft_rot(ret, sa, sb, 0);
			op(ret, PA, sa, sb);
		}
		else if ((*sb)->v > (*sa)->v)
			op(ret, RA, sa, sb);
		else if ((*sb)->v < (*sa)->v && (*sb)->v > (ft_end(sa))->v)
			op(ret, PA, sa, sb);
		else
			op(ret, RRA, sa, sb);
	}
}

int		ft_sort_3(t_stack **sa, t_stack **sb, t_out *ret)
{
	if (ft_length(*sa) != 3)
		return (0);
	if ((*sa)->v == find_lagest(*sa) && ((*sa)->nx)->v < (ft_end(sa))->v)
		return (1);
	else if ((*sa)->v > ((*sa)->nx)->v)
		op(ret, SA, sa, sb);
	else if ((*sa)->v == find_smallest(*sa) &&
			((*sa)->nx)->v == find_lagest(*sa))
		op(ret, SA, sa, sb);
	return (1);
}

int		ft_sort(t_stack **sa, t_stack **sb, t_out *ret, int size)
{
	int		i;
	int		num;

	i = 0;
	num = size;
	if (ft_length(*sa) != num)
		return (0);
	while (i < (num - 3))
	{
		ft_rot(ret, sa, sb, 0);
		op(ret, PB, sa, sb);
		i++;
	}
	ft_sort_3(sa, sb, ret);
	i = 0;
	while (i < (num - 3))
	{
		ft_rot(ret, sa, sb, 0);
		op(ret, PA, sa, sb);
		i++;
	}
	return (1);
}

void	ft_algo(t_stack **sa, t_stack **sb, t_out *ret)
{
	int		i;
	int		length;

	if (ft_ordered(*sa) == 1)
		return ;
	i = 0;
	length = 3;
	if (ft_length(*sa) > 101)
		length = 7;
	while (*sa)
	{
		if (ft_half_ordered(*sa) || ft_sort(sa, sb, ret, length))
		{
			ft_rot(ret, sa, sb, 0);
			ft_merge(sa, sb, ret);
			ft_rot(ret, sa, sb, 0);
			break ;
		}
		a_move(*sa);
		b_move(*sa, *sb);
		ft_move(*sa);
		ft_best_insertion(sa, sb, ret);
	}
}
