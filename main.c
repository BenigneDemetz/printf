#include "libftprintf.h"

int main (void)
{
    char *ptr = "b";
    void *ptrr = ptr;
    char str[] = "%u|%p|%c|%c|%c|%c|\%i";
    ft_printf(str, 2147483649, ptrr,'c','e','d','z', 1);
    printf("\n\%i\n", 1);
    return (0);
}