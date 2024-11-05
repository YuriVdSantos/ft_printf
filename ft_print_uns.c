/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:47:36 by yvieira-          #+#    #+#             */
/*   Updated: 2024/11/05 09:37:52 by yurivieirad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_print_unsigned(unsigned int n) {
	char	buffer[11];
	int		len = 0;
	int		i = 10;
    
	buffer[10] = '\0';
	do {
        buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	while (n);
	len += write(1, &buffer[i + 1], 10 - i);
	return len;
}