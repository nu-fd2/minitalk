/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:19:00 by oel-mado          #+#    #+#             */
/*   Updated: 2025/03/14 12:17:50 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf(const char *rei, ...)
{
	int		i;
	int		size;
	va_list	lain;

	va_start(lain, rei);
	i = 0;
	size = 0;
	if (write(1, NULL, 0) == -1)
		return (-1);
	while (rei[i])
	{
		if (rei[i] == '%')
		{
			size += ft_prints(rei, lain, ++i);
			i++;
		}
		else
			size += ft_putchar(rei[i++]);
	}
	va_end(lain);
	return (size);
}
