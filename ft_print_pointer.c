/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:19:23 by yvieira-          #+#    #+#             */
/*   Updated: 2024/11/11 21:27:30 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *ptr)
{
	unsigned long	addr;
	char			buffer[18];
	int				len;
	char			*base;
	int				i;

	len = 0;
	i = 17;
	base = "0123456789abcdef";
	buffer[17] = '\0';
	addr = (unsigned long)ptr;
	if (addr == 0)
	{
		return (write(1, "(nil)", 5));
	}
	while (addr)
	{
		buffer[i--] = base[addr % 16];
		addr /= 16;
	}
	len += write(1, "0x", 2);
	len += write(1, &buffer[i + 1], 17 - i);
	return (len);
}
