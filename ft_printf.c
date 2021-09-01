#include <stdio.h>
#include "ft_printf.h"

static int	type(const char *c, va_list ptr)
{
	int	len;

	len = 0;
	if (*c == 'c')
		len = wr_char(ptr);
	else if (*c == 's')
		len = wr_str(ptr);
	else if (*c == 'p')
		len = wr_hex(ptr, *c);
	else if (*c == 'd')
		len = wr_int(ptr);
	else if (*c == 'i')
		len = wr_int(ptr);
	else if (*c == 'u')
		len = wr_unsigned(ptr);
	else if (*c == 'x')
		len = wr_hex(ptr, *c);
	else if (*c == 'X')
		len = wr_hex(ptr, *c);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		len;

	va_start(ptr, str);
	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '%')
		{
			i++;
			len += type(&str[i], ptr);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
			len++;
		}
	}
	va_end(ptr);
	return (len);
}

/*
int	main(void)
{

	ft_printf("%c %c %c", ' ', ' ', ' ');

	ft_printf("%c %c %c", ' ', ' ', ' ');

	return (0);
}

*/
