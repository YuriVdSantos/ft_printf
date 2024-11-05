/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:34:00 by yvieira-          #+#    #+#             */
/*   Updated: 2024/11/05 11:14:42 by yurivieirad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#	define FT_PRINTF_H

#	include <stdarg.h>
#	include <unistd.h>
#	include <stdlib.h>
#	include <limits.h>

int	ft_print_unsigned(unsigned int n);
int	ft_print_string(const char *s);
int	ft_print_pointer(void *ptr);
int	ft_print_int(int n);
int	ft_print_hex(unsigned int n, int uppercase);
int	ft_print_char(int c);

#endif