/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:55:11 by oel-mado          #+#    #+#             */
/*   Updated: 2025/03/27 02:26:08 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sighand(int signum, siginfo_t *info, void *cnt)
{
	static char		byte;
	static int		pid;
	static int		i;

	(void)cnt;
	if (pid != info->si_pid)
	{
		i = 0;
		byte = 0;
		pid = info->si_pid;
	}
	byte = byte | (signum == SIGUSR2);
	i++;
	if (i >= 8)
	{
		if (byte != '\0')
			write(1, &byte, 1);
		else if (byte == '\0')
			kill(pid, SIGUSR1);
		byte = 0;
		i = 0;
	}
	else
		byte = byte << 1;
}

int	main(void)
{
	struct sigaction	s_sig;

	ft_memset(&s_sig, 0, sizeof(s_sig));
	s_sig.sa_sigaction = sighand;
	s_sig.sa_flags = SA_SIGINFO;
	write(1, "\033[1;33mPID:\033[0m ", 16);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sigaction(SIGUSR1, &s_sig, NULL);
	sigaction(SIGUSR2, &s_sig, NULL);
	while (69)
		pause();
	return (0);
}
