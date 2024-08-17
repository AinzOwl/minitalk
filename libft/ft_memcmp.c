/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:05:39 by efelaous          #+#    #+#             */
/*   Updated: 2023/11/27 14:22:06 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*x;
	unsigned char	*y;
	size_t			i;

	x = (unsigned char *) s1;
	y = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (x[i] != y[i])
			return (x[i] - y[i]);
		i++;
	}
	i--;
	if (n == 0)
		return (0);
	return (x[i] - y[i]);
}
