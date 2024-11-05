#include "ft_printf.h"

int	ft_print_hex(unsigned int n, int uppercase) {
	char	buffer[9];
	int		len = 0;
	char	*base = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	int		i = 8;

	buffer[8] = '\0';
	if (n == 0) {
		buffer[7] = '0';
		len += write(1, &buffer[7], 1);
	}
	else
	{
		while (n) {
			buffer[i--] = base[n % 16];
			n /= 16;
		}
		len += write(1, &buffer[i + 1], 8 - i);
	}
	return len;
}