/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psousa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:32:25 by psousa          #+#    #+#             */
/*   Updated: 2023/01/16 09:32:26 by psousa         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_bin(pid, argv[2]);
		ft_bin(pid, "\n");
	}
	else
		write(1, "Erro: Tenta ./client <Pid> <String>\n", 50);
	return (0);
}
