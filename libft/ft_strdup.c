/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:49:30 by efelaous          #+#    #+#             */
/*   Updated: 2023/11/03 15:56:45 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*xstr;
	char	*nstr;
	size_t	i;

	xstr = (char *) str;
	len = ft_strlen(xstr);
	nstr = (char *) ft_calloc(len + 1, sizeof(char));
	if (nstr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		nstr[i] = xstr[i];
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
