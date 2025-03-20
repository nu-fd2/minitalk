/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:17:06 by oel-mado          #+#    #+#             */
/*   Updated: 2025/03/19 23:58:28 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../libft/libft.h"

void	sigpr(int signum, siginfo_t *info, void *cnt)
{
	info = 0;
	cnt = 0;
	if (signum == SIGUSR1)
		ft_printf("\033[1;32mstring wsl\033[0m\n");
}

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
		usleep(128);
	}
}

void	val(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
		{
			ft_printf("\033[31;1mInvalid PID\033[0m\n");
			exit(1);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int					i;
	int					pid;
	struct sigaction	c_sig;

	i = 0;
	ft_memset(&c_sig, 0, sizeof(c_sig));
	c_sig.sa_sigaction = sigpr;
	c_sig.sa_flags = SA_SIGINFO;
	if (!av[2] || av[2][0] == '\0' || ac > 3 || ac < 3)
	{
		ft_printf("\033[33;1mTry ./client <PID> <MSG>\033[0m\n");
		exit(1);
	}
	val(av[1]);
	pid = ft_atoi(av[1]);
	if (pid <= 0 || kill(pid, 0) == -1)
	{
		ft_printf("\033[31;1mInvalid PID\033[0m\n");
		exit(1);
	}
	sigaction(SIGUSR1, &c_sig, NULL);
	while (av[2][i])
		send_char(av[2][i++], pid);
	send_char('\0', pid);
	return (0);
}
