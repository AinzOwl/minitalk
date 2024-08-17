/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:33:04 by efelaous          #+#    #+#             */
/*   Updated: 2023/11/27 09:52:25 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		len;

	nbr = n;
	if (nbr == 0)
		return (ft_substr("0", 0, 1));
	len = int_len(nbr);
	str = malloc((size_t)(len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	str[len] = 0;
	while (nbr > 0)
	{
		str[len - 1] = (nbr % 10) + 48;
		nbr = nbr / 10;
		len--;
	}
	return (str);
}
