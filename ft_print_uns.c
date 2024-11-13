/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:47:36 by yvieira-          #+#    #+#             */
/*   Updated: 2024/11/13 18:04:21 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	char	buffer[11];
	int		len;
	int		i;

	len = 0;
	i = 10;
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	buffer[10] = '\0';
	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	len += write(1, &buffer[i + 1], 10 - i);
	return (len);
}
