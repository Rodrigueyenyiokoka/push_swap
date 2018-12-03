/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 01:50:29 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/06/05 23:16:32 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *i;

	i = s1;
	while (*i != '\0')
	{
		i++;
	}
	while (*s2 != '\0' && n > 0)
	{
		*i = *s2;
		i++;
		s2++;
		n--;
	}
	*i = '\0';
	return (s1);
}
