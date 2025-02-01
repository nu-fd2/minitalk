/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 04:06:54 by oel-mado          #+#    #+#             */
/*   Updated: 2024/11/26 19:20:42 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);

int	ft_putchar(char c);
int	ft_putnbr(long n);
int	ft_putstr(char *s);
int	ft_putadr(unsigned long n);
int	ft_puthex(unsigned long n, const char *base);
int	ft_prints(const char *rei, va_list lain, int i);

#endif //FT_PRINTF_H
