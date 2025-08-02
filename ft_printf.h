/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorais- <tmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:50:33 by tmorais-          #+#    #+#             */
/*   Updated: 2025/08/02 14:48:05 by tmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int			ft_printf(const char *format, ...);

int			ft_strlen(char *s);
int			ft_putchar_count(char c);
int			ft_putstr_count(char *str);
int			ft_numlen(int n);
long		ft_abs(int n);
int			ft_print_int(int n);
int			ft_print_unsigned(unsigned int n);
char		*ft_itoa(int n);
char		*ft_utoa(unsigned int n);
int			ft_numlen_base(unsigned long n, int base);
int			ft_print_char(int c);
int			ft_handle_null_string(void);
int			ft_print_string(char *str);
int			ft_print_percent(void);
int			ft_isvalid_conversion(char c);
char		*ft_convert_to_hex(unsigned long n, int uppercase);
int			ft_print_hex_prefix(void);
int			ft_print_hex_lower(unsigned int n);
int			ft_print_hex_upper(unsigned int n);
int			ft_print_pointer(void *ptr);

#endif