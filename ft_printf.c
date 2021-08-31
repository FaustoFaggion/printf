#include <stdio.h>
#include "libftprintf.h"

char	wr_char(va_list ptr)
{
	char	s;

	s = va_arg(ptr, int);
	write(1, &s, 1);
	return (s);
}

char	*wr_str(va_list ptr)
{
	char	*s;

	s = va_arg(ptr, char *);
	write(1, s, ft_strlen(s));
	return (s);
}

void	wr_ptr(va_list ptr)
{
	char			base[16] = "0123456789abcdef";
	unsigned long	p;

	p = va_arg(ptr, unsigned long);
	write(1, "0x", 2);
 	ft_putnbr_base(p, base);
}


char	*wr_int(va_list ptr)
{
	int		nb;
	char	*s;

	nb = va_arg(ptr, int);
	s = ft_itoa(nb);
	write(1, s, ft_strlen(s));
	return (s);
}

void	wr_x(va_list ptr)
{
	char			base[16] = "0123456789abcdef";
	unsigned long	p;

	p = va_arg(ptr, unsigned long);
 	ft_putnbr_base(p, base);
}

wr_j(char *c, va_list ptr)
{
	int	i;

	i = 0;
	if (c[i + 1] == 'u')
	{
		write(1, '#', 1);
		p = va_arg(ptr, unsigned int);
 		ft_putnbr_base(p, base);
	}
	if (c[i + 1] == 'x')
	{
		write(1, '#', 1);
		p = va_arg(ptr, unsigned long);
 		ft_putnbr_base(p, base);
	}
}

void	*type(const char *c, va_list ptr)
{

	if (*c == 'c')
		wr_char(ptr);
	else if (*c == 's')
		wr_str(ptr);
	else if (*c == 'p')
		wr_ptr(ptr);
	else if (*c == 'd')
		wr_int(ptr);
	//else if (*c == 'i')

	//else if (*c == 'u')

	else if (*c == 'x')
		wr_x(ptr);
	else if (*c == '#')
		wr_j(ptr, c);

}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		ret;
	void	*arg;

	va_start(ptr, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				write(1, "%", 1);
			else
			{
				type(&str[i], ptr);
				i++;
			}
		}
		write(1, &str[i], 1);
		i++;
	}
	va_end(ptr);
	ret = ft_strlen(str);
	return(ret);
}

int main(void)
{
	int		str1 = 100;
	char	str2[] = "42";

	setbuf(stdout, NULL);
	ft_printf("Nome: %x idade: %s \n", str1, str2);

	printf("Nome: %x idade: %s \n", str1, str2);

	//printf("Nome: %s idasde: %s \n", str1, str2);
	return (0);
}


/*
primeira

#include <stdio.h>
#include <stdarg.h>

size_t	ft_strlen(const char *s)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	count_(const char *str)
{
	int	i;
	int	count;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			count++;
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		ret;

	va_start(ptr, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			printf("%s", va_arg(ptr, char *));
			i++;
		}
		printf("%c", str[i]);
		i++;
	}
	va_end(ptr);

	ret = ft_strlen(str);
	return(ret);

}

int main(void)
{
	char	str1[] = "Fausto";
	char	str2[] = "42";

	ft_printf("Nome: % idade: % \n", "Fausto", str2);

	//printf("Nome: %s idasde: %s \n", str1, str2);
	return (0);
}
*/
