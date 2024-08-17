/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:11:38 by efelaous          #+#    #+#             */
/*   Updated: 2023/11/10 22:03:05 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*string;
	char	x;

	x = c;
	string = (char *) str;
	while (*string != x)
	{
		if (!*string && x != 0)
			return (NULL);
		string++;
	}
	if (*string || (!*string && !x))
		return (string);
	return (NULL);
}
