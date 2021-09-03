#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>

char	*ft_strdup(const char *s);

size_t	ft_strlen(const char *s);

char	*ft_itoa(int n);

char	*ft_unsigned_itoa(int n);

int		ft_printf(const char *str, ...);

int		ft_printf_base(unsigned long p, char *base);

int		wr_char(va_list ptr, char c);

int		wr_str(va_list ptr);

int		wr_int(va_list ptr);

int		wr_unsigned(va_list ptr);

//int		wr_hex(va_list ptr, char c);

int		wr_p_hex(va_list ptr);

int		wr_x_hex(va_list ptr, char c);
#endif
