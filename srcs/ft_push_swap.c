/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:55:45 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/09/18 16:28:34 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;
	t_out	*ret;

	stacka = NULL;
	stackb = NULL;
	if (!(stacka = ft_is_integer(argc, argv, stacka)))
		return (0);
	ret = ft_out_initialize();
	ft_algo(&stacka, &stackb, ret);
	ft_print_1(ret);
	ft_free(&stacka, &stackb, &ret);
	return (0);
}
