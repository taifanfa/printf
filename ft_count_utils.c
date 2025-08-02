/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorais- <tmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:19:48 by tmorais-          #+#    #+#             */
/*   Updated: 2025/08/02 15:02:50 by tmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar_count(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr_count(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[count])
	{
		ft_putchar_count(str[count]);
		count++;
	}
	return (count);
}

int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
		if (n == 0)
			return (len);
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

long	ft_abs(int n)
{
	if (n < 0)
		return (-(long)n);
	return ((long)n);
}
