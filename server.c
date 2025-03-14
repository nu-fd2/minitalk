/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:55:11 by oel-mado          #+#    #+#             */
/*   Updated: 2025/03/14 15:37:26 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void sighand(int signum)
{
	static char byte;
	static int i;

	byte = byte | (signum == SIGUSR2);
	i++;
	if (i == 8)
	{
		if (byte != '\0')
			ft_printf("%c", byte);
		else
			ft_printf("\n");
		i = 0;
		ft_bzero(&byte, 1);
	}
	else
		byte = byte << 1;
}

int main()
{
	ft_printf("PID: \033[1;33m%d\n\033[0m", getpid());
	signal(SIGUSR1, sighand);
	signal(SIGUSR2, sighand);
	while (69)
		pause();
	return 0;
}
