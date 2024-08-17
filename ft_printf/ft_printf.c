/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:53:29 by efelaous          #+#    #+#             */
/*   Updated: 2023/12/19 15:06:58 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_checker(char c)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		if ("cspdiuxX%"[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	sp_printadr(unsigned long long n, char *hex)
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

int	sp_printptr(unsigned long ptr)
{
	int	rtn;

	if (!ptr)
		return (rtn = write(1, "0x0", 3), rtn);
	rtn = write(1, "0x", 2);
	rtn += sp_printadr(ptr, "0123456789abcdef");
	return (rtn);
}

int	sp_handle_format(char c, int *specifier, size_t *len, va_list args)
{
	int	x;

	*specifier = 0;
	if (c == 's')
		return (sp_putstr((char *){va_arg(args, char *)}));
	else if (c == 'c')
		return (write(1, &(int){va_arg(args, int)}, 1));
	else if (c == 'p')
		return (sp_printptr((unsigned long) va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
	{
		return (x = 0, sp_putnbr((int){va_arg(args, int)}, &x));
	}
	else if (c == 'u')
		return (sp_printunsigned((unsigned int){va_arg(args, unsigned int)}));
	else if (c == 'x')
		return (sp_printhex((unsigned long){va_arg(args, unsigned long)},
			"0123456789abcdef"));
	else if (c == 'X')
		return (sp_printhex((unsigned long){va_arg(args, unsigned long)},
			"0123456789ABCDEF"));
	else if (c == '%')
		return (write(1, &c, 1));
	else
		return (write(1, &c, 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	size_t	len;
	int		specifier;

	if (write(1, "0", 0))
		return (-1);
	va_start(args, format);
	i = 0;
	specifier = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && specifier == 0)
		{
			specifier = 1;
			i++;
		}
		else if (format[i] != '%' & specifier == 0)
			len += write(1, &format[i++], 1);
		else
			len += sp_handle_format(format[i++], &specifier, &len, args);
	}
	va_end(args);
	return (len);
}
