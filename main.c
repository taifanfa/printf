#include "ft_printf.h"
#include <stdio.h>  // para comparação com printf original

int	main(void)
{
	int	ret1, ret2;
	char	c = 'A';
	char	*str = "Hello, 42!";
	void	*ptr = &str;
	int		d = -12345;
	int		i = 54321;
	unsigned int u = 4294967295;
	int		hex = 48879;

	ft_printf("=== ft_printf ===\n");
	ret1 = ft_printf("Char: %c\n", c);
	ft_printf("Return: %d\n\n", ret1);

	ret1 = ft_printf("String: %s\n", str);
	ft_printf("Return: %d\n\n", ret1);

	ret1 = ft_printf("Pointer: %p\n", ptr);
	ft_printf("Return: %d\n\n", ret1);

	ret1 = ft_printf("Decimal: %d\n", d);
	ft_printf("Return: %d\n\n", ret1);

	ret1 = ft_printf("Integer: %i\n", i);
	ft_printf("Return: %d\n\n", ret1);

	ret1 = ft_printf("Unsigned: %u\n", u);
	ft_printf("Return: %d\n\n", ret1);

	ret1 = ft_printf("Hex lowercase: %x\n", hex);
	ft_printf("Return: %d\n\n", ret1);

	ret1 = ft_printf("Hex UPPERCASE: %X\n", hex);
	ft_printf("Return: %d\n\n", ret1);

	ret1 = ft_printf("Percent: %%\n");
	ft_printf("Return: %d\n\n", ret1);

	// Comparação com printf original
	printf("=== printf original ===\n");
	ret2 = printf("Char: %c\n", c);
	printf("Return: %d\n\n", ret2);

	ret2 = printf("String: %s\n", str);
	printf("Return: %d\n\n", ret2);

	ret2 = printf("Pointer: %p\n", ptr);
	printf("Return: %d\n\n", ret2);

	ret2 = printf("Decimal: %d\n", d);
	printf("Return: %d\n\n", ret2);

	ret2 = printf("Integer: %i\n", i);
	printf("Return: %d\n\n", ret2);

	ret2 = printf("Unsigned: %u\n", u);
	printf("Return: %d\n\n", ret2);

	ret2 = printf("Hex lowercase: %x\n", hex);
	printf("Return: %d\n\n", ret2);

	ret2 = printf("Hex UPPERCASE: %X\n", hex);
	printf("Return: %d\n\n", ret2);

	ret2 = printf("Percent: %%\n");
	printf("Return: %d\n\n", ret2);

	return (0);
}
