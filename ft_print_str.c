/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:14:00 by yvieira-          #+#    #+#             */
/*   Updated: 2024/11/05 09:34:24 by yurivieirad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(const char *s) {
	int	len = 0;

	if (!s)
		s = "(null)";
	while (s[len])
		write(1, &s[len++], 1);
	return len;
}