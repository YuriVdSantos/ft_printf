/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:32:05 by yvieira-          #+#    #+#             */
/*   Updated: 2024/11/04 20:01:39 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_print_chr(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_print_str(const char *str)
{
	int	count;

	count = 0;
	if (*str == '\0')
		str = "(null)";
	while (*str)
	{
		count += write (1, str, 1);
		str++;
	}
	return (count);
}

char	ft_print_int(int n)
{
	char	str[12];
	int		is_neg;
	int		i;
	int		count;
	
	i = 0;
	i = 10;
	str[11] = '0';
	is_neg = (n < 0);
	if (is_neg)
		n = -n;
	if (n == 0)
		return (write (1, "0", 1));
	while (n && i >= 0)
	{
		str[i--] = '0' + (n % 10);
		n = (n / 10);
	}
	count += write(1, &str[i + 1], 11 - i - 1);
	return (count);
}

char	ft_print_unsigned(int n)
{
	char	str[12];
	int		is_neg;
	int		i;
	int		count;
	
	i = 0;
	i = 10;
	str[11] = '0';
	is_neg = (n < 0);
	if (is_neg)
		n *= -1;
	if (n == 0)
		return (write (1, "0", 1));
	while (n && i >= 0)
	{
		str[i--] = '0' + (n % 10);
		n = (n / 10);
	}
	count += write(1, &str[i + 1], 11 - i - 1);
	return (count);
}


int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;

	count = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				count += ft_print_chr(va_arg(arg, int));
			else if (*format == 's')
				count += ft_print_str(va_arg(arg, char *));
			else if (*format == 'd' || *format == 'i')
				count += ft_print_int(va_arg(arg, int));
			else if (*format == '%')
				count += write(1, "%", 1);
			else if (*format == 'u')
				count += ft_print_unsigned(va_arg(arg, int));
				
		}
		else
			count += write (1, format, 1);
		format++;
	}
	va_end(arg);
	return (count);
}

int main ()
{
    ft_printf("Character: %c\n", 'A');
    ft_printf("Character: %s\n", "TEST");
    ft_printf("Integer: %d\n", 1234);
    ft_printf("Integer: %i\n", 1);
	ft_printf ("Teste %% %%\n");
	ft_printf ("Teste %u\n", -852);

}


// int	ft_printf(const char *format, ...)
// {
// 	va_list	arg;
// 	int		count;

// 	count = 0;
// 	va_start(arg, format);
// 	while (*format)
// 	{
// 		if (*format == '%')
// 		{
// 			format++;
// 			if (*format == 'c')
// 				count += ft_print_chr(va_arg(arg, int));
// 			else if (*format == 's')
// 				count += ft_print_str(va_arg(arg, int));
// 			else if (*format == 'd')
// 				count += ft_print_int(va_arg(arg, int));
// 			else if (*format == '%')
// 				write (1, '%', 1);
// 			else
// 				count += write(1, format, 1);
// 		}
// 		else
// 			count += write (1, format, 1);
// 		format++;
// 	}
// 	va_end(arg);
// 	return (count);
// }