/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:54:29 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/09/18 14:54:33 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_position(t_stack *sb, int j)
{
	int		goal;
	t_stack	*tmp;
	int		loc;
	int		i;

	tmp = sb;
	goal = j;
	loc = 0;
	i = 0;
	while (tmp)
	{
		if (goal == tmp->v)
		{
			loc = i;
		}
		tmp = tmp->nx;
		i++;
	}
	return (loc <= (i / 2) ? 1 : -1);
}

void	a_move(t_stack *sa)
{
	int		i;
	t_stack	*tmpa2;

	i = 0;
	tmpa2 = sa;
	while (sa)
	{
		sa->maf = i;
		sa = sa->nx;
		i++;
	}
	tmpa2->mar = 0;
	tmpa2 = tmpa2->nx;
	i--;
	while (tmpa2)
	{
		tmpa2->mar = i;
		tmpa2 = tmpa2->nx;
		i--;
	}
}

void	b_move(t_stack *sa, t_stack *sb)
{
	int		i;
	t_stack	*tmpb;

	if (!(sb))
		return ;
	while (sa)
	{
		i = 0;
		tmpb = sb;
		if (sa->v < (ft_end(&tmpb)->v) && sa->v > tmpb->v)
			;
		else if (sa->v > find_lagest(sb))
			i = b_move_largest(tmpb, sb);
		else if (sa->v < find_smallest(sb))
			i = b_move_smallest(tmpb, sb);
		else if (sa->v > (ft_end(&tmpb)->v) && sa->v > tmpb->v)
			i = help_m1(sa, tmpb);
		else
			i = help_m2(tmpb, sa);
		sa->mbf = i;
		sa->mbr = (ft_length(sb)) - i;
		sa = sa->nx;
	}
}

void	ft_move(t_stack *sa)
{
	int		*ar;

	ar = (int *)malloc(sizeof(int) * 4);
	while (sa)
	{
		ar[0] = ((sa->maf > sa->mbf) ? sa->maf : sa->mbf);
		ar[1] = ((sa->mar > sa->mbr) ? sa->mar : sa->mbr);
		ar[2] = sa->maf + sa->mbr;
		ar[3] = sa->mar + sa->mbf;
		ft_help_m3(sa, ar);
		sa = sa->nx;
	}
	free(ar);
}
