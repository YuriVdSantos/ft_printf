/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:19:18 by yvieira-          #+#    #+#             */
/*   Updated: 2024/11/11 21:16:23 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int n)
{
	char	buffer[12];
	int		len;
	int		i;

	len = 0;
	if (n == INT_MIN)
	{
		len += write(1, "-", 1);
		n = -(n + 1);
		len += write(1, "2147483648", 10);
		return (len);
	}
	if (n == 0)
	{
		return (write(1, "0", 1));
	}
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
