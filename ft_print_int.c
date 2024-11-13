/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:19:18 by yvieira-          #+#    #+#             */
/*   Updated: 2024/11/13 16:04:52 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_int_min(int *len, int *n)
{
	if (*n == INT_MIN)
	{
		*len += write(1, "-2147483648", 11);
		return (1);
	}
	return (0);
}

int	ft_print_int(int n)
{
	char	buffer[12];
	int		len;
	int		i;

	len = 0;
	if (is_int_min(&len, &n))
		return (len);
	if (n == 0)
		return (write(1, "0", 1));
	if (n < 0)
	{
		len += write(1, "-", 1);
		n = -n;
	}
	buffer[11] = '\0';
	i = 10;
	while (n)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	len += write(1, &buffer[i + 1], 10 - i);
	return (len);
}
