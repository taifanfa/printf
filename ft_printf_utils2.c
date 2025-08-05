#include "ft_printf.h"

static int	ft_strlen_base(char *base)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	return (len);
}

static int	ft_count_digits(unsigned long n, int base_len)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= base_len;
		count++;
	}
	return (count);
}

static void	ft_fill_buffer(unsigned long nbr, char *base, char *buffer, int i)
{
	int	base_len;

	base_len = ft_strlen_base(base);
	buffer[i] = '\0';
	while (nbr > 0)
	{
		buffer[--i] = base[nbr % base_len];
		nbr /= base_len;
	}
}

int	ft_print_nbr(long n, char *base)
{
	int				base_len;
	int				count;
	unsigned long	nbr;
	char			buffer[65];

	base_len = ft_strlen_base(base);
	count = 0;
	if (n < 0 && base_len == 10)
	{
		count += ft_putchar_count('-');
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr == 0)
		return (count + ft_putchar_count('0'));
	ft_fill_buffer(nbr, base, buffer, ft_count_digits(nbr, base_len));
	count += ft_putstr_count(buffer);
	return (count);
}
