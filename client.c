/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:17:06 by oel-mado          #+#    #+#             */
/*   Updated: 2025/03/14 15:37:18 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void send_char(int c, int pid)
{
	int i;

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

int main(int ac, char **av)
{
	int i;
	int pid;

	i = 0;
	pid = ft_atoi(av[1]);
	if (!av[1] || pid == 0 || !av[2] || ac > 3 || ac < 3)
	{
		if (pid == 0 || !av[1])
			ft_printf("\033[31;1mInvalid PID\033[0m\n");
		if (!av[2] || ac > 3 || ac < 3)
			ft_printf("\033[33;1mDo: ./client <PID> \"MSG\"\033[0m\n");
		exit(1);
	}
	while (av[2][i])
		send_char(av[2][i++], pid);
	send_char('\0', pid);
	return (0);
}
