/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:05:36 by efelaous          #+#    #+#             */
/*   Updated: 2023/11/27 11:40:29 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*sp_neg(char *str, int *neg)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		*neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	return (str);
}

int	ft_atoi(const char *str)
{
	long	in;
	int		neg;
	char	*st;
	long	temp;

	neg = 1;
	st = sp_neg((char *) str, &neg);
	in = 0;
	temp = 0;
	while (*st >= '0' && *st <= '9')
	{
		in = (in * 10) + (*st - 48);
		if (in < temp && neg == 1)
			return (-1);
		else if (in < temp && neg == -1)
			return (0);
		temp = in;
		st++;
	}
	return (neg * in);
}
