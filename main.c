/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:24:02 by yvieira-          #+#    #+#             */
/*   Updated: 2024/11/04 15:45:38 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main() {
    // ft_printf("Hello, %s!\n", "world");  // Teste para strings
    // ft_printf("Character: %c\n", 'A');    // Teste para char
    // ft_printf("Integer: %d\n", 1234);     // Teste para inteiros
    // ft_printf("Percentage: %%\n");        // Teste para %
    
    unsigned int i = -10;

    return printf("%u", i);
}
