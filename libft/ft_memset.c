/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:40:18 by efelaous          #+#    #+#             */
/*   Updated: 2023/11/12 21:37:04 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int cm, size_t len)
{
	unsigned char	*x;

	x = b;
	while (len--)
	{
		*x = cm;
		x++;
	}
	return (b);
}
