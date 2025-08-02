/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorais- <tmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:56:55 by tmorais-          #+#    #+#             */
/*   Updated: 2025/08/02 15:00:20 by tmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int n)
{
	int		count;
	long	abs_value;
	char	digits[12];
	int		digit_count;

	count = 0;
	if (n == 0)
	{
		count += ft_putchar_count('0');
		return (count);
	}
	if (n < 0)
		count += ft_putchar_count('-');
	abs_value = ft_abs(n);
	digit_count = 0;
	while (abs_value > 0)
	{
		digits[digit_count] = '0' + (abs_value % 10);
		abs_value = abs_value / 10;
		digit_count++;
	}
	while (digit_count > 0)
		count += ft_putchar_count(digits[--digit_count]);
	return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count += ft_putchar_count('0');
		return (count);
	}
	if (n >= 10)
		count += ft_print_unsigned(n / 10);
	count += ft_putchar_count('0' + (n % 10));
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nbr;

	len = ft_numlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	nbr = n;
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 0)
	{
		str[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

char	*ft_utoa(unsigned int n)
{
	int		len;
	char	*str;

	len = ft_numlen_base(n, 10);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (n > 0)
	{
		str[--len] = '0' + (n % 10);
		n = n / 10;
	}
	return (str);
}

int	ft_numlen_base(unsigned long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n = n / base;
	}
	return (len);
}
