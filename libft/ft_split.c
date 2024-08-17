/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:47:21 by efelaous          #+#    #+#             */
/*   Updated: 2023/11/22 19:49:29 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sp_words(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i == 0)
		{
			while (s[i] == c && s[i] != '\0')
				i++;
			if (s[i] == '\0')
				return (0);
		}
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i] == c || s[i] == '\0')
			j++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (j);
}

static int	sp_count(char *s, char c)
{
	int		j;

	j = 0;
	while (*s == c && *s)
		s++;
	while (*s != c && *s)
	{
		s++;
		j++;
	}
	return (j);
}

static char	*sp_dup(char *s, int j, char **arr, int k)
{
	char	*str;
	int		i;

	str = malloc((j + 1) * sizeof(char));
	if (!str)
	{
		k--;
		while (k >= 0)
			free(arr[k--]);
		return (NULL);
	}
	i = 0;
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

static char	**split_output(int i, char *str, char c, char **arr)
{
	int		j;
	int		k;

	k = 0;
	while (k < i)
	{
		while (*str == c && *str)
			str++;
		j = sp_count(str, c);
		arr[k] = sp_dup(str, j, arr, k);
		if (!arr[k])
		{
			free(arr);
			return (NULL);
		}
		str += j + 1;
		k++;
	}
	arr[k] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	char	*str;

	if (s == NULL)
		return (NULL);
	str = (char *) s;
	i = sp_words(str, c);
	arr = malloc((i + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (split_output(i, str, c, arr));
}
