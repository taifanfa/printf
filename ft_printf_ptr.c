#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int				count;
	unsigned long	addr;

	count = 0;
	if (!ptr)
		return (ft_putstr_count("(nil)"));
	addr = (unsigned long)ptr;
	count += ft_putchar_count('0');
	count += ft_putchar_count('x');
	count += ft_print_nbr(addr, "0123456789abcdef");
	return (count);
}
