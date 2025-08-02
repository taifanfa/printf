/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorais- <tmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:41:39 by tmorais-          #+#    #+#             */
/*   Updated: 2025/08/02 13:47:45 by tmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	return (ft_putchar_count((char)c));
}

int	ft_handle_null_string(void)
{
	return (ft_putstr_count("(null)"));
}

int	ft_print_string(char *str)
{
	if (!str)
		return (ft_handle_null_string());
	return (ft_putstr_count(str));
}

int	ft_print_percent(void)
{
	return (ft_putchar_count('%'));
}

int	ft_isvalid_conversion(char c)
{
	char	*valid_conversion;
	int		i;

	valid_conversion = "cspdiuxX%";
	i = 0;
	while (valid_conversion[i])
	{
		if (valid_conversion[i] == c)
			return (1);
		i++;
	}
	return (0);
}
