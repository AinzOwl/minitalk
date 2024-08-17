/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:32:23 by efelaous          #+#    #+#             */
/*   Updated: 2023/11/10 22:32:26 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*string;
	char	*cc;
	char	x;

	x = c;
	string = (char *) str;
	cc = NULL;
	while (*string)
	{
		if (*string == x)
			cc = string;
		string++;
	}
	if (x == '\0')
		return (string);
	return (cc);
}
