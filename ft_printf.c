#include <stdio.h>
#include "ft_printf.h"

static int	type(const char *c, va_list ptr)
{
	int	len;

	len = 0;
	if (*c == 'c')
		len = wr_char(ptr, *c);
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
	else if (*c == '%')
		len = wr_char(ptr, *c);
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
		if (str[i] == '%')
		{
			i++;
			len += type(&str[i], ptr);
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(ptr);
	return (len);
}

int	main(void)
{
	//int	s = 255;


	ft_printf(" %d ", -1);

	return (0);
}
