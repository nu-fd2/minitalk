/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:17:06 by oel-mado          #+#    #+#             */
/*   Updated: 2025/02/04 20:11:42 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_puthex(int n)
{
	char *base = "01";

	if (n >= 2)
	{
		ft_puthex(n / 2);
		ft_putchar(base[n % 2]);
	}
	else
		ft_putchar(base[n]);
}

// void to_bit(char *m_byte)
// {
// 	int i;

// 	while 
// }

// void send_char(int c, int pid)
// {
// 	int i;
// 	char m_byte[8];
// 	to_bit(m_byte);
// 	while (i <= 7)
// 	{
// 		if ()
// 			kill(pid, SIGUSR1);//0
// 		else
// 			kill(pid, SIGUSR2);//1
// 	}
// }

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
