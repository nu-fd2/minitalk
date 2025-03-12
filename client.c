/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:17:06 by oel-mado          #+#    #+#             */
/*   Updated: 2025/03/12 17:54:23 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_char(int c, int pid)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (c >> i & 1)
		{
			kill(pid, SIGUSR2);
			ft_printf("0");
		}
		else
		{
			kill(pid, SIGUSR1);
			ft_printf("1");
		}
		i++;
	}
}

int main(int ac, char **av)
{
	int i;
	int f;
	int pid;

	i = 0;
	f = 1;
	if (ac != 3)
		exit(0);
	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		if (!f)
			ft_printf(" ");
		f = 0;
		send_char(av[2][i], pid);
		i++;
	}
	return (0);
}
