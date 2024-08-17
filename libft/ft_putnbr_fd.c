/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:26:18 by efelaous          #+#    #+#             */
/*   Updated: 2024/08/14 22:35:12 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_fd(int nbr, int fd)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", fd);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", fd);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		write(1, &"0123456789"[nbr % 10], fd);
	}
	else
	{
		write(1, &"0123456789"[nbr], fd);
	}

}
