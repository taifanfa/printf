#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_putchar_count(char c);
int		ft_putstr_count(char *str);
int		ft_print_nbr(long n, char *base);
int		ft_print_ptr(void *ptr);

#endif
