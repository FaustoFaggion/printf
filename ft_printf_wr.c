#include "ft_printf.h"
#include <stdio.h>

int	wr_char(va_list ptr, char c)
{
	char	s;
	int		len;

	if (c == 'c')
	{
		s = va_arg(ptr, int);
		write(1, &s, 1);
	}
	else if (c == '%')
	{
		s = '%';
		write(1, &s, 1);
	}
	len = 1;
	return (len);
}

int	wr_str(va_list ptr)
{
	char	*s;
	int		len;

	s = va_arg(ptr, char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

int	wr_int(va_list ptr)
{
	int		nb;
	char	*s;
	int		len;

	nb = va_arg(ptr, int);
	s = ft_itoa(nb);
	len = ft_strlen(s);
	write(1, s, len);
	free(s);
	return (len);
}

int	wr_unsigned(va_list ptr)
{
	unsigned int	nb;
	char			*s;
	int				len;

	nb = va_arg(ptr, unsigned int);
	s = ft_unsigned_itoa(nb);
	len = ft_strlen(s);
	write(1, s, len);
	free(s);
	return (len);
}
