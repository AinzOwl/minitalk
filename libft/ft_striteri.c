/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:29:11 by efelaous          #+#    #+#             */
/*   Updated: 2023/11/11 00:40:09 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	len;
	unsigned int	i;

	if (f == NULL || s == NULL)
		return ;
	len = ft_strlen((char *) s);
	i = 0;
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}
