/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psousa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:46:15 by psousa          #+#    #+#             */
/*   Updated: 2023/01/16 14:46:16 by psousa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	handler(int signal, siginfo_t *info, void *content)
{
	static int	bit;
	static int	i;

	(void)content;
	if (signal == SIGUSR1)
		i += 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(i, 1);
		if (i == '\0')
			kill(info->si_pid, SIGUSR2);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	action;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		write(1, "Pid:", 4);
		ft_putnbr_fd(pid, 1);
		write(1, "\n", 1);
		action.sa_sigaction = &handler;
		sigemptyset(&action.sa_mask);
		action.sa_flags = SA_RESTART | SA_SIGINFO;
		while (1)
		{
			sigaction(SIGUSR1, &action, NULL);
			sigaction(SIGUSR2, &action, NULL);
			pause();
		}
	}
	else
		ft_putstr_fd("Erro: Tenta ./server_bonus", 1);
	return (0);
}
