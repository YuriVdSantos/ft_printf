/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:34:00 by yvieira-          #+#    #+#             */
/*   Updated: 2024/11/13 18:04:26 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int	ft_print_unsigned(unsigned int n);
int	ft_print_string(const char *s);
int	ft_print_pointer(void *ptr);
int	ft_print_int(int n);
int	ft_print_hex(unsigned int n, int uppercase);
int	ft_printf(const char *format, ...);

#endif