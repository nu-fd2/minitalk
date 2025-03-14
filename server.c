/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:55:11 by oel-mado          #+#    #+#             */
/*   Updated: 2025/03/14 12:57:49 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void sighand(int signum)
{
	static char *byte;
	static int i;

	i = 0;
	
	if (signum == SIGUSR2)
		ft_printf("1");
	else if (signum == SIGUSR1)
		ft_printf("0");
}

int main()
{
	ft_printf("Process ID: \033[1;33m%d\n\033[0m", getpid());
	signal(SIGUSR1, sighand);
	signal(SIGUSR2, sighand);
	while (69)
		pause();
	return 0;
}
