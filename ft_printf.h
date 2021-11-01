#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct s_print
{
	int					i;
	int					len;
	char				c;
	char				*s;
	unsigned long int	p;
	int					d;
	unsigned int		u;
	unsigned int		x;
	unsigned int		X;
	char				flag_hash;
	char				flag_;
	char				flag_plus;
	char				flag_minus;
	char				flag_width;
}				t_print;


# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

//char	*ft_strdup(const char *s);

//size_t	ft_strlen(const char *s);

//char	*ft_itoa(int n);

char	*ft_unsigned_itoa(int n);

int		ft_printf(const char *str, ...);

int		ft_printf_base(unsigned long p, char *base);

int		wr_char(va_list ptr, char c);

int		wr_str(va_list ptr);

int		wr_int(va_list ptr);

int		wr_unsigned(va_list ptr);

int		wr_hex(va_list ptr, char c);

//bonus

char	*ft_strchr(const char *s, int c);

#endif
