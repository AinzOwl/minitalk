/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:22:20 by efelaous          #+#    #+#             */
/*   Updated: 2023/11/11 00:13:56 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_len(char	*str1, size_t len)
{
	size_t	i;

	i = ft_strlen(str1);
	if (len > i)
		len = i;
	return (len);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (len == 0 && haystack == NULL)
		return (NULL);
	if (!*needle)
		return ((char *) haystack);
	len = check_len((char *) haystack, len);
	i = 0;
	while (i < len && *haystack)
	{
		j = 0;
		while (haystack[j + i] == needle[j] && i + j < len)
		{
			if (!needle[j + 1])
				return ((char *) &haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
