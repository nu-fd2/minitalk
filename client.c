/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:17:06 by oel-mado          #+#    #+#             */
/*   Updated: 2025/02/04 22:22:23 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*to_bin(int n)
{
	int i;
	char *bin;

    bin = malloc(9);
	i = 7;
	while (i >= 0)
	{
		if (n % 2 == 0)
			bin[i] = '0';
		else
			bin[i] = '1';
		n /= 2;
		i--;
	}
	bin[8] = '\0';
	return (bin);
}

void send_char(int c, int pid)
{
	int i;
	char *bits;

	i = 0;
	bits = to_bit(c);
	while (i <= 7)
	{
		if (bits[i] == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
	}
	free(bits);
}

int main(int ac, char **av)
{
	int i;
	int pid;

	i = 0;
	if (ac != 3)
		exit(0);
	pid = ft_atoi(av[1]);
	ft_printf("%d", pid);
	while (av[2][i])
	{
		send_char(av[2][i], pid);
		i++;
	}
}
