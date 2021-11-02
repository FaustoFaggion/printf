/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:53:26 by fausto            #+#    #+#             */
/*   Updated: 2021/11/02 10:59:40 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

char	*ft_unsigned_itoa(int n);

int		ft_printf(const char *str, ...);

int		ft_printf_base(unsigned long p, char *base);

int		wr_char(va_list ptr, char c);

int		wr_str(va_list ptr);

int		wr_int(va_list ptr);

int		wr_unsigned(va_list ptr);

int		wr_hex(va_list ptr, char c);

#endif
