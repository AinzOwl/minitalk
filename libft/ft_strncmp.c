/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:36:36 by efelaous          #+#    #+#             */
/*   Updated: 2023/11/02 21:31:07 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*x;
	unsigned char	*y;

	if (n <= 0)
		return (0);
	i = 0;
	x = (unsigned char *) s1;
	y = (unsigned char *) s2;
	while (x[i] && y[i] && i < n - 1)
	{
		if (x[i] != y[i])
			return (x[i] - y[i]);
		i++;
	}
	if (i > n && x[i] == y[i])
		return (0);
	return (x[i] - y[i]);
}
