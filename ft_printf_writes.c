#include "libftprintf.h"

int	wr_char(va_list ptr)
{
	char	s;
	int		len;

	s = va_arg(ptr, int);
	write(1, &s, 1);
	len = 1;
	return (len);
}

int	wr_str(va_list ptr)
{
	char	*s;
	int		len;

	s = va_arg(ptr, char *);
	write(1, s, ft_strlen(s));
	len = ft_strlen(s);
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

int	wr_hex(va_list ptr, char c)
{
	unsigned long int	p;
	int					len;

	len = 0;
	p = va_arg(ptr, unsigned long int);
	if (c == 'p')
	{
		write(1, "0x", 2);
		len = ft_putnbr_base(p, "0123456789abcdef");
		len += 2;
	}
	else if (c == 'x')
		len = ft_putnbr_base(p, "0123456789abcdef");
	else if (c == 'X')
		len = ft_putnbr_base(p, "0123456789ABCDEF");
	return (len);
}
