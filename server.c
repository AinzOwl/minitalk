/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:04:29 by efelaous          #+#    #+#             */
/*   Updated: 2024/08/17 10:23:07 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minitalk.h"



void handle_sigusr(int signum, siginfo_t *info, void *context)
{
	static char	c = 0xFF;
    static int	bits = 0;
    static char	*msg = NULL;
    static int	pid = 0;

    (void)context;
	if (info->si_pid != pid)
	{
        pid = info->si_pid;
		bits=0;
		if (msg)
			free(msg);
		msg = NULL;
		c = 0xFF;
	} 
	else if (info->si_pid)
	{
		pid = info->si_pid;
	}
    if (signum == SIGUSR1)
        c ^= 0x80 >> bits;
    else if (signum == SIGUSR2)
        c |= 0x80 >> bits;  
    bits++;
    if (bits == 8)
    {
        if (c == '\0')
		{
            ft_printf("%s\n", msg);
			free(msg);
			msg = NULL;
		}
        else
            msg = ft_appendchar(msg, c);
        bits = 0;
        c = 0xFF;
    }
	if (kill(pid, SIGUSR1) == -1)
        error(1, msg);
}

int main()
{
    struct sigaction    sa;
    sigset_t            block_mask;

    sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa.sa_handler = 0;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = block_mask;
	sa.sa_sigaction = handle_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	ft_printf("PID: %d\n", getpid());

	while (1)
		pause();
}
