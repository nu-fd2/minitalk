/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:43:56 by oel-mado          #+#    #+#             */
/*   Updated: 2025/03/26 14:07:26 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

long	ft_atol(const char *str)
{
	long	nb;
	int		sg;
	int		i;

	i = 0;
	sg = 1;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sg = -sg;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb * sg);
}

static int	ft_intlen(long nbr)
{
	int	i;

	i = 1;
	if (nbr < 0)
		i++;
	while (nbr >= 10 || nbr <= -10)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(long n)
{
	char	m;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n <= 0)
	{
		if (n == 0)
		{
			write(1, "0", 1);
			return (1);
		}
		write(1, "-", 1);
		ft_putnbr(-n);
	}
	if (n >= 10)
		(ft_putnbr(n / 10), ft_putnbr(n % 10));
	else if (n >= 0 && n <= 9)
	{
		m = n + 48;
		write(1, &m, 1);
	}
	return (ft_intlen(n));
}

void	*ft_memset(void *ptr, int n, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
		((unsigned char *)ptr)[i++] = (unsigned char)n;
	return (ptr);
}
