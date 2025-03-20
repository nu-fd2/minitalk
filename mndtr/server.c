/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:55:11 by oel-mado          #+#    #+#             */
/*   Updated: 2025/03/19 23:58:44 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../libft/libft.h"

void	sighand(int signum, siginfo_t *info, void *cnt)
{
	static char		byte;
	static int		i;
	static int		pid;

	if (pid != info->si_pid)
	{
		i = 0;
		byte = 0;
		pid = info->si_pid;
	}
	byte = byte | (signum == SIGUSR2);
	i++;
	cnt = 0;
	if (i == 8)
	{
		if (byte != '\0')
			ft_printf("%c", byte);
		i = 0;
		byte = 0;
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
	ft_printf("PID: \033[1;33m%d\n\033[0m", getpid());
	sigaction(SIGUSR1, &s_sig, NULL);
	sigaction(SIGUSR2, &s_sig, NULL);
	while (69)
		pause();
	return (0);
}
