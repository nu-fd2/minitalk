/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 01:43:44 by oel-mado          #+#    #+#             */
/*   Updated: 2024/11/26 01:44:30 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prints(const char *rei, va_list lain, int i)
{
	char	*up;
	char	*down;

	up = "0123456789ABCDEF";
	down = "0123456789abcdef";
	if (rei[i] == 's')
		return (ft_putstr(va_arg(lain, char *)));
	else if (rei[i] == 'c')
		return (ft_putchar(va_arg(lain, int)));
	else if (rei[i] == 'd' || rei[i] == 'i')
		return (ft_putnbr((long)va_arg(lain, int)));
	else if (rei[i] == 'u')
		return (ft_putnbr((unsigned long)va_arg(lain, unsigned int)));
	else if (rei[i] == '%')
		return (ft_putchar('%'));
	else if (rei[i] == 'x')
		return (ft_puthex((unsigned int)va_arg(lain, void *), down));
	else if (rei[i] == 'X')
		return (ft_puthex((unsigned int)va_arg(lain, void *), up));
	else if (rei[i] == 'p')
		return (ft_putadr((unsigned long)va_arg(lain, void *)));
	return (0);
}
