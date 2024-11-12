/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:56:49 by yvieira-          #+#    #+#             */
/*   Updated: 2024/11/11 21:33:37 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_hex_conversion(unsigned int n, char *base)
{
	char	buffer[9];
	int		len;
	int		i;

	len = 0;
	i = 8;
	buffer[8] = '\0';
	if (n == 0)
	{
		buffer[7] = '0';
		len += write(1, &buffer[7], 1);
	}
	else
	{
		while (n)
		{
			buffer[i--] = base[n % 16];
			n /= 16;
		}
		len += write(1, &buffer[i + 1], 8 - i);
	}
	return (len);
}

int	ft_print_hex(unsigned int n, int uppercase)
{
	char	*base;
	int		len;

	len = 0;
	if (uppercase)
	{
		base = "0123456789ABCDEF";
	}
	else
	{
		base = "0123456789abcdef";
	}
	len += process_hex_conversion(n, base);
	return (len);
}
