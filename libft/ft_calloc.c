/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:29:31 by efelaous          #+#    #+#             */
/*   Updated: 2023/11/27 11:56:58 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned char	*x;
	size_t			len;

	if (count > 0 && size > 0)
		if (count > (size_t) - 1 / size)
			return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	len = 0;
	x = ptr;
	while (len < count * size)
	{
		x[len] = 0;
		len++;
	}
	return (ptr);
}
