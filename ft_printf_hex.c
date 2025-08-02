/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorais- <tmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:49:52 by tmorais-          #+#    #+#             */
/*   Updated: 2025/08/02 14:48:57 by tmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_to_hex(unsigned long n, int uppercase)
{
	int		len;
	char	*str;
	char	*hex_chars;

	if (uppercase)
		hex_chars = "0123456789ABCDEF";
	else
		hex_chars = "0123456789abcdef";
	len = ft_numlen_base(n, 16);
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
		str[--len] = hex_chars[n % 16];
		n /= 16;
	}
	return (str);
}

int	ft_print_hex_prefix(void)
{
	int	count;

	count = 0;
	count += ft_putchar_count('0');
	count += ft_putchar_count('x');
	return (count);
}

int	ft_print_hex_lower(unsigned int n)
{
	char	*hex_str;
	int		count;

	count = 0;
	hex_str = ft_convert_to_hex(n, 0);
	if (!hex_str)
		return (0);
	count += ft_putstr_count(hex_str);
	free(hex_str);
	return (count);
}

int	ft_print_hex_upper(unsigned int n)
{
	char	*hex_str;
	int		count;

	count = 0;
	hex_str = ft_convert_to_hex(n, 1);
	if (!hex_str)
		return (0);
	count += ft_putstr_count(hex_str);
	free(hex_str);
	return (count);
}

int	ft_print_pointer(void *ptr)
{
	unsigned long	addr;
	char			*hex_str;
	int				count;

	count = 0;
	if (!ptr)
		return (ft_putstr_count("(nil)"));
	addr = (unsigned long)ptr;
	count += ft_print_hex_prefix();
	hex_str = ft_convert_to_hex(addr, 0);
	if (!hex_str)
		return (count);
	count += ft_putstr_count(hex_str);
	free(hex_str);
	return (count);
}
