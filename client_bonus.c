/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psousa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:46:06 by psousa          #+#    #+#             */
/*   Updated: 2023/01/16 14:46:07 by psousa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

void	ft_bin(int pid, char *msg)
{
	int	i;
	int	j;

	i = 0;
	while (msg[i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			if (msg[i] >> j & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			j--;
		}
		i++;
	}
}

void	ft_null(int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

void	handler(int signal)
{
	if (signal == SIGUSR2)
		write(1, "Mensagem Entregue!\n", 19);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	action;

	if (argc == 3)
	{
		action.sa_handler = &handler;
		sigemptyset(&action.sa_mask);
		action.sa_flags = 0;
		sigaction(SIGUSR2, &action, NULL);
		pid = ft_atoi(argv[1]);
		ft_bin(pid, argv[2]);
		ft_bin(pid, "\n");
		ft_null(pid);
	}
	else
		write("Erro: Tenta ./client_bonus <Pid> <String>\n", 50);
	return (0);
}
