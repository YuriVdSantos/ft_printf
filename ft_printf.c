#include "ft_printf.h"

int ft_printf(const char *format, ...) {
    va_list args;
    int total_length = 0;  // Corrigido para contar o total de caracteres impressos
    int count = 0;         // Contador de caracteres impressos

    va_start(args, format);

    while (*format) {
        if (*format == '%' && *(format + 1) == '%') {
            write(1, "%", 1);
            count++;
            format += 2;  // Avança para o próximo caractere após %%
        } else if (*format == '%') {
            format++;  // Avança para o tipo de conversão
            if (*format == 'c') {
                char c = va_arg(args, int);
                count += write(1, &c, 1);
            } else if (*format == 's') {
                count += ft_print_string(va_arg(args, const char *));
            } else if (*format == 'd' || *format == 'i') {
                count += ft_print_int(va_arg(args, int));
            } else if (*format == 'u') {
                count += ft_print_unsigned(va_arg(args, unsigned int));
            } else if (*format == 'x') {
                count += ft_print_hex(va_arg(args, unsigned int), 0);
            } else if (*format == 'X') {
                count += ft_print_hex(va_arg(args, unsigned int), 1);
            } else if (*format == 'p') {
                count += ft_print_pointer(va_arg(args, void *));
            }
            format++;  // Avança para o próximo caractere do formato
        } else {
            count += write(1, format, 1);  // Imprime o caractere atual
            format++;  // Avança para o próximo caractere
        }
    }

    va_end(args);
    return count;  // Retorna o total de caracteres impressos
}
