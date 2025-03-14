/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:17:06 by oel-mado          #+#    #+#             */
/*   Updated: 2025/03/14 12:38:51 by oel-mado         ###   ########.fr       */
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
		usleep(500);
	}
}

int main(int ac, char **av)
{
	int i;
	int pid;

	i = 0;
	if (ac != 3)
		exit(0);
	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		send_char(av[2][i], pid);
		i++;
	}
	send_char('\0', pid);
	return (0);
}
