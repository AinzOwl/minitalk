/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:22:42 by efelaous          #+#    #+#             */
/*   Updated: 2023/11/11 00:38:51 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	trim_end(char *str, char *set)
{
	int		i;
	size_t	j;

	j = ft_strlen(str);
	i = 0;
	while (set[i] && j > 0)
	{
		if (str[j - 1] == set[i])
		{
			j--;
			i = -1;
		}
		i++;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	size_t	j;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	str = (char *) s1;
	i = 0;
	while (set[i])
	{
		if (*str == set[i])
		{
			str++;
			i = -1;
		}
		i++;
	}
	j = trim_end(str, (char *) set);
	return (ft_substr(str, 0, j));
}
