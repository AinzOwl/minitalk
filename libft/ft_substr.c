/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:00:58 by efelaous          #+#    #+#             */
/*   Updated: 2023/11/11 00:30:55 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rstr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start > (unsigned int) ft_strlen((char *) s))
		return (ft_strdup(""));
	i = (int) ft_strlen((char *) &s[start]);
	if (i < len)
		len = i;
	rstr = (char *) malloc((len + 1) * sizeof(char));
	if (rstr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		rstr[i] = s[start];
		i++;
		start++;
	}
	rstr[i] = '\0';
	return (rstr);
}
