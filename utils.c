/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:35:55 by efelaous          #+#    #+#             */
/*   Updated: 2024/08/17 09:21:57 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	error(int pid, char *str)
{
	if (str)
		free(str);
	if (pid == 1)
		write(2, "[SERVER]: Unexpected error has occured!\n", 40);
	else if(pid == -1)
		write(2, "[CLIENT]: Unexpected error has occured!\n", 40);
	exit(1);
}

char	*ft_chartostr(char c)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = 0;
	return (str);
}

char	*ft_appendchar(char *str, char c)
{
	char	*nstr;
	int		i;

	if (!c)
		return (NULL);
	if (!str)
		return (ft_chartostr(c));
	nstr = (char *) malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!nstr)
		return (free(str), NULL);
	i = 0;
	while (str[i])
	{
		nstr[i] = str[i];
		i++;
	}
	free(str);
	nstr[i] = c;
	nstr[i+1] = 0;
	return (nstr);
}
