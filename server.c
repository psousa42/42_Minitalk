/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psousa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:32:31 by psousa          #+#    #+#             */
/*   Updated: 2023/01/16 09:32:32 by psousa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	ft_msg(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i += 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(i, 1);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		write(1, "Pid:", 4);
		ft_putnbr_fd(pid, 1);
		write(1, "\n", 1);
		while (1)
		{
			signal(SIGUSR1, ft_msg);
			signal(SIGUSR2, ft_msg);
			pause();
		}
	}
	else
		ft_putstr_fd("Erro: Tenta ./server", 1);
	return (0);
}
