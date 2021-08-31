#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>

char	*ft_strdup(const char *s);

size_t	ft_strlen(const char *s);

char	*ft_itoa(int n);

void ft_putnbr_base(unsigned long nbr, char *base);

#endif
