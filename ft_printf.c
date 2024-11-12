/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:46:13 by yvieira-          #+#    #+#             */
/*   Updated: 2024/11/11 21:46:30 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_format(const char *format, va_list args)
{
	char	c;
	int		count;

	count = 0;
	if (*format == 'c')
	{
		c = va_arg(args, int);
		count += write(1, &c, 1);
	}
	else if (*format == 's')
		count += ft_print_string(va_arg(args, const char *));
	else if (*format == 'd' || *format == 'i')
		count += ft_print_int(va_arg(args, int));
	else if (*format == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	else if (*format == 'x')
		count += ft_print_hex(va_arg(args, unsigned int), 0);
	else if (*format == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), 1);
	else if (*format == 'p')
		count += ft_print_pointer(va_arg(args, void *));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_length;
	int		count;

	total_length = 0;
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) == '%')
		{
			write(1, "%", 1);
			count++;
			format += 2;
		}
		else if (*format == '%')
		{
			format++;
			count += process_format(format, args);
			format++;
		}
		else
		{
			count += write(1, format, 1);
			format++;
		}
	}
	va_end(args);
	return (count);
}
