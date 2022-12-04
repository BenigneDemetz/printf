#include "libftprintf.h"

static unsigned int printf_prct_count(const char *input)
{
    unsigned int i;
    unsigned int cpt;

    i = 0;
    cpt = 0;
    while (i < ft_strlen(input))
    {
        if (input[i] == '%' && input[i + 1] && input[i + 1] != '%')
            cpt++;
        i++;
    }
    return (cpt);
}

short int char_trtm(char c, va_list args)
{
    short int error;

    if (c == 'c')
        error = ft_putchar_fd((char) va_arg(args, int), 1);
    else if (c == 's')
        error = ft_putstr_fd(va_arg(args, char *), 1);
    else if (c == 'p')
        error = ft_putnbr_fd(va_arg(args, unsigned long), 1);
    else if (c == 'd' || input[i] == 'i')
        error = ft_putnbr_fd(va_arg(args, int), 1);
    else if (c == 'u')
        error = ft_putunsigned_fd(va_arg(args, unsigned int), 1);
    else if (c == 'x')
        error = ft_putstr_fd(va_arg(args, char *), 1);
    else if (c == 'X')
        error = ft_putstr_fd(va_arg(args, char *), 1);
    else if (c == '%')
        error = ft_putchar_fd('%', 1);
    return (error);
}

int ft_printf(const char *input, ...)
{
    va_list args;
    unsigned int cpt;
    unsigned int i;
    unsigned int j;

    i = j = 0;
    cpt = printf_prct_count(input);
    va_start(args, input);
    while (i < ft_strlen(input))
    {
        if ((j < cpt || (input[i + 1] && input[i + 1] == '%')) && input[i] == '%')
        {
            i++;
            j++;
            if (char_trtm(input[i]) == -1)
                return (-1);
        }
        else
            ft_putchar_fd(input[i], 1);
        i++;
    }
    va_end(args);
    return (i - j);
}
