/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:35:35 by efelaous          #+#    #+#             */
/*   Updated: 2024/08/17 09:17:37 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_format_checker(char c);
int		sp_putstr(char *s);
int		sp_putnbr(int n, int *len);
int		sp_printhex(unsigned int n, char *hex);
int		sp_printptr(unsigned long ptr);
int		sp_printunsigned(unsigned int n);
int		sp_printadr(unsigned long long n, char *hex);

#endif