/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:53:41 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/09/18 14:53:44 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		help_m1(t_stack *sa, t_stack *tmpb)
{
	int		i;

	i = 0;
	while (sa->v > tmpb->v)
	{
		i++;
		tmpb = tmpb->nx;
	}
	while (sa->v < tmpb->v)
	{
		i++;
		tmpb = tmpb->nx;
	}
	return (i);
}

int		help_m2(t_stack *tmpb, t_stack *sa)
{
	int		i;

	i = 0;
	while (sa->v < tmpb->v)
	{
		i++;
		tmpb = tmpb->nx;
	}
	return (i);
}

void	ft_help_m3(t_stack *sa, int *ar)
{
	if (ar[0] <= ar[1] && ar[0] <= ar[2] && ar[0] <= ar[3])
	{
		sa->moves = ar[0];
		sa->dir = 1;
	}
	else if (ar[1] <= ar[0] && ar[1] <= ar[2] && ar[1] <= ar[3])
	{
		sa->moves = ar[1];
		sa->dir = 2;
	}
	else if (ar[2] <= ar[0] && ar[2] <= ar[1] && ar[2] <= ar[3])
	{
		sa->moves = ar[2];
		sa->dir = 3;
	}
	else if (ar[3] <= ar[1] && ar[3] <= ar[0] && ar[3] <= ar[2])
	{
		sa->moves = ar[3];
		sa->dir = 4;
	}
}

int		b_move_smallest(t_stack *tmpb, t_stack *sb)
{
	int		i;

	i = 1;
	while (tmpb->v != find_smallest(sb))
	{
		i++;
		tmpb = tmpb->nx;
	}
	return (i);
}

int		b_move_largest(t_stack *tmpb, t_stack *sb)
{
	int		i;

	i = 0;
	while (tmpb->v != find_lagest(sb))
	{
		i++;
		tmpb = tmpb->nx;
	}
	return (i);
}
