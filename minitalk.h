/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:04:04 by efelaous          #+#    #+#             */
/*   Updated: 2024/08/17 09:22:03 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define M_BUFFER_SIZE 1000

void	error(int pid, char *str);
char	*ft_chartostr(char c);
char	*ft_appendchar(char *str, char c);


#endif