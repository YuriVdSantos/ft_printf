#include "ft_printf.h"

int ft_print_pointer(void *ptr) {
    unsigned long addr = (unsigned long)ptr;
    char buffer[18];
    int len = 0;
    char *base = "0123456789abcdef";
    int i = 17;

    buffer[17] = '\0';  // Null-terminate the buffer

    if (addr == 0) {
        // Handle NULL pointer case
        return write(1, "0x0", 3);  // Print "0x0" for NULL pointer
    } 

    // Reset the buffer and convert the address to hex
    while (addr) {
        buffer[i--] = base[addr % 16];  // Convert address to hex
        addr /= 16;
    }
    
    len += write(1, "0x", 2);  // Print "0x" prefix
    len += write(1, &buffer[i + 1], 17 - i);  // Print the hex address from the buffer

    return len;  // Return total length printed
}
