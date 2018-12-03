/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:53:09 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/09/18 14:53:20 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_op	*create_op_list(void)
{
	t_op *list;

	list = (t_op *)(malloc(sizeof(t_op)));
	list->op = nothing;
	list->call = NULL;
	list->next = NULL;
	return (list);
}

int		call_op(t_op *list, char *line)
{
	if (!(ft_strcmp(line, "sa")))
		list->call = &sa_op;
	else if (!(ft_strcmp(line, "sb")))
		list->call = &sb_op;
	else if (!(ft_strcmp(line, "ss")))
		list->call = &ss_op;
	else if (!(ft_strcmp(line, "pa")))
		list->call = &pa_op;
	else if (!(ft_strcmp(line, "pb")))
		list->call = &pb_op;
	else if (!(ft_strcmp(line, "ra")))
		list->call = &ra_op;
	else if (!(ft_strcmp(line, "rb")))
		list->call = &rb_op;
	else if (!(ft_strcmp(line, "rr")))
		list->call = &rr_op;
	else if (!(ft_strcmp(line, "rra")))
		list->call = &rra_op;
	else if (!(ft_strcmp(line, "rrb")))
		list->call = &rrb_op;
	else if (!(ft_strcmp(line, "rrr")))
		list->call = &rrr_op;
	else
		return (1);
	return (0);
}

int		op_history(t_op *list, char *line)
{
	if (!(ft_strcmp(line, "sa")))
		list->op = sa;
	else if (!(ft_strcmp(line, "sb")))
		list->op = sb;
	else if (!(ft_strcmp(line, "ss")))
		list->op = ss;
	else if (!(ft_strcmp(line, "pa")))
		list->op = pa;
	else if (!(ft_strcmp(line, "pb")))
		list->op = pb;
	else if (!(ft_strcmp(line, "ra")))
		list->op = ra;
	else if (!(ft_strcmp(line, "rb")))
		list->op = rb;
	else if (!(ft_strcmp(line, "rr")))
		list->op = rr;
	else if (!(ft_strcmp(line, "rra")))
		list->op = rra;
	else if (!(ft_strcmp(line, "rrb")))
		list->op = rrb;
	else if (!(ft_strcmp(line, "rrr")))
		list->op = rrr;
	else
		return (1);
	return (0);
}

void	get_next_op_sub(char *line, t_op *list, t_op *prev)
{
	while (get_next_line(0, &line))
	{
		if (call_op(list, line))
		{
			if (ft_strequ(line, ""))
			{
				free(line);
				break ;
			}
			write(2, "Error\n", 6);
			exit(1);
		}
		op_history(list, line);
		list->next = create_op_list();
		prev = list;
		list = list->next;
		free(line);
	}
	free(list);
	prev->next = NULL;
}

t_op	*get_next_op(void)
{
	char	*line;
	t_op	*list;
	t_op	*begin;
	t_op	*prev;

	line = NULL;
	list = create_op_list();
	begin = list;
	prev = list;
	get_next_op_sub(line, list, prev);
	return (begin);
}
