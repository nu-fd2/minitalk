/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 04:37:09 by oel-mado          #+#    #+#             */
/*   Updated: 2025/03/14 12:28:56 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

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
