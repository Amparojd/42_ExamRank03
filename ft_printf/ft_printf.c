/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:49:45 by ampjimen          #+#    #+#             */
/*   Updated: 2024/05/21 18:57:05 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

void put_str(char *str, int *len)
{
    if(!str)
        str = "(null)";
    while(*str)
        *len += write(1, str++, 1);
}

void put_digit(long long int number, int base, int *len)
{
    char *hexa = "0123456789abcdef";

    if(number < 0)
    {
        number *= -1;
        *len += write(1, "-", 1);
    }
    if(number >= base)
        put_digit(number/base, base, len);
    *len += write(1, &hexa[number%base], 1);
}

int ft_printf(const char *format, ...)
{
    int len = 0;
    int i = 0;

    va_list (args);
    va_start(args, format);

    while(format[i])
    {
        if(format[i] == '%' && format[i + 1])
        {
            i++;
            if(format[i] == 's')
                put_str(va_arg(args, char *), &len);
            else if(format[i] == 'd')
                put_digit((long long int)va_arg(args, int), 10, &len);
            else if(format[i] == 'x')
                put_digit((long long int)va_arg(args, unsigned int), 16, &len);
        }
        else
            len += write(1, &format[i], 1);
        i++;
    }
    va_end(args);
    return(len);
}
