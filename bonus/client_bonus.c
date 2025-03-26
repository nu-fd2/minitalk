/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:17:06 by oel-mado          #+#    #+#             */
/*   Updated: 2025/03/26 04:57:40 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_char(int c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c >> (7 - i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		usleep(512);
	}
}

void	val(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!(pid[i] >= '0' && pid[i] <= '9'))
		{
			write(1, "\033[31;1mInvalid PID\033[0m\n", 23);
			exit(1);
		}
		i++;
	}
}

void	sigpr(int signum)
{
	if (signum == SIGUSR1)
		write(1, "\033[1;32mMSG is received\033[0m\n", 27);
}

int	main(int ac, char **av)
{
	int					i;
	long				pid;
	struct sigaction	c_sig;

	i = 0;
	ft_memset(&c_sig, 0, sizeof(c_sig));
	c_sig.sa_handler = sigpr;
	if (!av[2] || av[2][0] == '\0' || ac != 3)
	{
		write(1, "\033[33;1mTry ./client <PID> <MSG>\033[0m\n", 36);
		exit(1);
	}
	val(av[1]);
	pid = ft_atol(av[1]);
	if ((pid <= 0 || kill((int)pid, 0) == -1) || pid > 2147483647)
	{
		write(1, "\033[31;1mInvalid PID\033[0m\n", 23);
		exit(1);
	}
	sigaction(SIGUSR1, &c_sig, NULL);
	while (av[2][i])
		send_char(av[2][i++], (int)pid);
	send_char('\0', (int)pid);
	return (0);
}
