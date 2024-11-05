
#include "ft_printf.h"

int ft_print_int(int n) {
    char buffer[12];  // Buffer suficiente para armazenar o inteiro mais o sinal e o nulo
    int len = 0;

    // Tratar INT_MIN
    if (n == INT_MIN) {
        len += write(1, "-", 1);  // Escreve o sinal negativo
        n = -(n + 1);  // Aumenta para lidar com o overflow
        len += write(1, "2147483648", 10);  // Imprime "2147483648"
        return len;  // Retorna o comprimento total
    }

    if (n < 0) {
        len += write(1, "-", 1);
        n = -n;  // Converte n para positivo
    }
    
    buffer[11] = '\0';  // Null-terminate the buffer
    int i = 10;
    do {
        buffer[i--] = (n % 10) + '0';  // Converte dígitos para caractere
        n /= 10;  // Divide n por 10
    } while (n);

    len += write(1, &buffer[i + 1], 10 - i);  // Escreve os dígitos restantes

    return len;  // Retorna o comprimento total
}
