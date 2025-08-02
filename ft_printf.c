/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorais- <tmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:06:52 by tmorais-          #+#    #+#             */
/*   Updated: 2025/08/02 14:53:07 by tmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_process_conversion(char conversion, va_list args)
{
	int	count;

	count = 0;
	if (conversion == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (conversion == 's')
		count += ft_print_string(va_arg(args, char *));
	else if (conversion == 'p')
		count += ft_print_pointer(va_arg(args, void *));
	else if (conversion == 'd' || conversion == 'i')
		count += ft_print_int(va_arg(args, int));
	else if (conversion == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	else if (conversion == 'x')
		count += ft_print_hex_lower(va_arg(args, unsigned int));
	else if (conversion == 'X')
		count += ft_print_hex_upper(va_arg(args, unsigned int));
	else if (conversion == '%')
		count += ft_print_percent();
	return (count);
}

static int	ft_parse_format(const char *format, va_list args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (ft_isvalid_conversion(format[i]))
				count += ft_process_conversion(format[i], args);
			else
			{
				count += ft_putchar_count('%');
				count += ft_putchar_count(format[i]);
			}
		}
		else if (format[i] == '%' && !format[i + 1])
			count += ft_putchar_count('%');
		else
			count += ft_putchar_count(format[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	count += ft_parse_format(format, args);
	va_end(args);
	return (count);
}
