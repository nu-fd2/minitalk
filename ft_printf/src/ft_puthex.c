/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 04:37:09 by oel-mado          #+#    #+#             */
/*   Updated: 2024/11/24 15:22:40 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *who)
{
	int	ask;

	ask = 0;
	while (who[ask])
		ask++;
	return (ask);
}

int	ft_puthex(unsigned long n, const char *base)
{
	unsigned long	len;
	int				i;

	len = ft_strlen(base);
	i = 0;
	if (n >= len)
	{
		i += ft_puthex(n / len, base);
		i += ft_putchar(base[n % len]);
	}
	else
		i += ft_putchar(base[n]);
	return (i);
}
