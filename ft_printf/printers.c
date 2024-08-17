/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 00:41:42 by efelaous          #+#    #+#             */
/*   Updated: 2024/08/17 09:17:35 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	sp_putstr(char *s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	sp_putnbr(int n, int *len)
{
	long	nbr;

	nbr = n;
	if (nbr == 0)
	{
		*len += write(1, "0", 1);
		return (*len);
	}
	if (nbr < 0)
	{
		*len += write(1, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr >= 10)
	{
		sp_putnbr(nbr / 10, len);
		sp_putnbr(nbr % 10, len);
	}
	else
		*len += write(1, &"0123456789"[nbr], 1);
	return (*len);
}

int	sp_printhex(unsigned int n, char *hex)
{
	int	x[20];
	int	i;
	int	len;

	if (n == 0)
		return (write(1, "0", 1));
	i = 0;
	len = 0;
	while (n > 0)
	{
		x[i] = n % 16;
		n = n / 16;
		i++;
	}
	i--;
	len = 0;
	while (i >= 0)
		len += write(1, &hex[x[i--]], 1);
	return (len);
}

int	sp_printunsigned(unsigned int n)
{
	int	x[20];
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		x[i] = n % 10;
		n = n / 10;
		i++;
	}
	i--;
	len = 0;
	while (i >= 0)
		len += write(1, &"0123456789"[x[i--]], 1);
	return (len);
}
