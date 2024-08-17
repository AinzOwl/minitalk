/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:39:54 by efelaous          #+#    #+#             */
/*   Updated: 2023/11/02 22:03:54 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*x;
	size_t			i;
	char			z;

	x = (char *) s;
	i = 0;
	z = c;
	while (i < n)
	{
		if (x[i] == z)
			return ((unsigned char *)&s[i]);
		i++;
	}
	return (NULL);
}
