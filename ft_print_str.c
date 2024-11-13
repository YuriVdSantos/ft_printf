/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:14:00 by yvieira-          #+#    #+#             */
/*   Updated: 2024/11/13 18:04:19 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		s = "(null)";
	while (s[len])
		write(1, &s[len++], 1);
	return (len);
}
