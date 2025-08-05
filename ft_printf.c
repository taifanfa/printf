#include "ft_printf.h"

static int	ft_process_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_count(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr_count(va_arg(args, char *)));
	if (c == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(args, int), "0123456789"));
	if (c == 'u')
		return (ft_print_nbr(va_arg(args, unsigned int), "0123456789"));
	if (c == 'x')
		return (ft_print_nbr(va_arg(args, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_print_nbr(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (c == '%')
		return (ft_putchar_count('%'));
	return (ft_putchar_count('%') + ft_putchar_count(c));
}

static int	ft_is_valid(char c)
{
	char	*valid = "cspdiuxX%";
	int		i;

	i = 0;
	while (valid[i])
	{
		if (valid[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_parse(const char *format, va_list args)
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
			if (ft_is_valid(format[i]))
				count += ft_process_format(format[i], args);
			else
				count += ft_putchar_count('%') + ft_putchar_count(format[i]);
		}
		else if (format[i] == '%')
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
	if (format[0] == '\0')
    	return (0);
	va_start(args, format);
	count = ft_parse(format, args);
	va_end(args);
	return (count);
}
