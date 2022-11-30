#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"

static int printf_prct_count(const char *input)
{
    unsigned int i;
    unsigned int cpt;

    i = 0;
    cpt = 0;
    while (i < ft_strlen((char *) input))
        if (input[i++] == '%')
            cpt++;
    return (cpt);
}

int ft_printf(const char *input, ...)
{
    va_list print_args;
    int cpt;

    cpt = printf_prct_count(input);
    va_start(print_args, input);
    for (int i = 0; i < cpt; i++)
    {
        printf("%i%i",va_arg(print_args, int), cpt);
    }
    va_end(print_args);
}

int main (void)
{
    ft_printf("%s", 1,2,6,4,5,6);
    return (0);
}