/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:16:05 by czheng-c          #+#    #+#             */
/*   Updated: 2023/06/12 10:48:38 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hex(unsigned long nb, char ch, int *i)
{
	if (nb >= 10 && ch == 'u')
		ft_hex(nb / 10, ch, i);
	else if (nb >= 16)
		ft_hex(nb / 16, ch, i);
	if (ch == 'x' || ch == 'p')
		ft_putchar_fd("0123456789abcdef"[nb % 16], 1);
	else if (ch == 'X')
		ft_putchar_fd("0123456789ABCDEF"[nb % 16], 1);
	else if (ch == 'u')
		ft_putchar_fd("0123456789"[nb % 10], 1);
	(*i)++;
}

int	ft_int(va_list arg)
{
	char	*temp;
	int		num;
	int		length;

	length = 0;
	num = va_arg(arg, int);
	temp = ft_itoa(num);
	length = ft_strlen(temp);
	write(1, temp, length);
	free(temp);
	return (length);
}

int	ft_check(char *format, int i, va_list arg)
{
	char	*temp;
	int		length;

	length = 1;
	if (format[i] == 'c')
	{
		temp = va_arg(arg, char *);
		write(1, &temp, 1);
	}
	else if (format[i] == 's')
	{
		temp = va_arg(arg, char *);
		if (!temp)
			return (write(1, "(null)", 6));
		length = ft_strlen(temp);
		write(1, temp, length);
	}
	else if (format[i] == '%')
		write(1, "%", 1);
	else if (format[i] == 'd' || format[i] == 'i')
		length = ft_int(arg);
	return (length);
}

int	ft_base16(char *format, int i, va_list arg)
{
	int				length;
	unsigned long	b;

	length = 0;
	b = va_arg(arg, unsigned long);
	if (format[i] == 'x')
		ft_hex(b, 'x', &length);
	else if (format[i] == 'X')
		ft_hex(b, 'X', &length);
	else if (format[i] == 'u')
		ft_hex(b, 'u', &length);
	else if (format[i] == 'p')
	{
		write(1, "0x", 2);
		ft_hex(b, 'p', &length);
		length += 2;
	}
	return (length);
}

int	ft_printf(char *format, ...)
{
	va_list	arg;
	int		i;
	int		ret;

	i = -1;
	ret = 0;
	va_start(arg, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'x' || format[i + 1] == 'X'
				|| format[i + 1] == 'p'
				|| format[i + 1] == 'u')
				ret += ft_base16(format, i + 1, arg);
			else
				ret += ft_check(format, i + 1, arg);
			i++;
		}
		else
			ret += write(1, &format[i], 1);
	}
	va_end(arg);
	return (ret);
}
