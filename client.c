/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:14:39 by efelaous          #+#    #+#             */
/*   Updated: 2024/08/17 09:23:26 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_null(int pid, char *str)
{
	static int	bit = 0;

	if (bit++ != 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			error(-1, str);
		return (0);
	}
	return (1);
}

int	send_bit(int pid, char *str)
{
	static char	*message = 0;
	static int	s_pid = 0;
	static int	bits = -1;

	if (str)
		message = ft_strdup(str);
	if (!message)
		error(-1, 0);
	if (pid)
		s_pid = pid;
	if (message[++bits / 8])
	{
		if (message[bits / 8] & (0x80 >> (bits % 8)))
		{
			if (kill(s_pid, SIGUSR2) == -1)
				error(-1, message);
		}
		else if (kill(s_pid, SIGUSR1) == -1)
			error(-1, message);
		return (0);
	}
	if (!send_null(s_pid, message))
		return (0);
	free(message);
	return (1);
}

void	handler_sigusr(int signum)
{
	int	end;

	end = 0;
	if (signum == SIGUSR1)
		end = send_bit(0, 0);
	else if (signum == SIGUSR2)
	{
		ft_putstr_fd("client: server ended unexpectdly.\n", 2);
		exit(EXIT_FAILURE);
	}
	if (end)
	{
		ft_printf("client: operation successful.\n");
		exit(EXIT_SUCCESS);
	}
}

int ft_isnumeric(char *str)
{
	int	i;

	i = 1;
	while(*str)
	{
		if (*str < '0' || *str > '9')
			i = 0;
		str++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_isnumeric(argv[1]))
	{
		ft_printf("client: invalid arguments.\ncorrect format: [./client <PID> <STR>].\n");
		exit(1);
	}
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	send_bit(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}