/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wr_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:46:16 by fagiusep          #+#    #+#             */
/*   Updated: 2021/09/03 15:49:48 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	wr_p_hex(va_list ptr, char c)
{
	unsigned long int	p;
	int					len;

	len = 0;
	p = va_arg(ptr, unsigned long int);
	write(1, "0x", 2);
	len += 2;
	len = ft_printf_base(p, "0123456789abcdef");
	return (len);
}

int wr_x_hex(va_list ptr, char c)
{
	unsigned int	p;
	int				len;

	len = 0;
	p = va_arg(ptr, unsigned long int);
	if (c == 'x')
		len = ft_printf_base(p, "0123456789abcdef");
	else if (c == 'X')
		len = ft_printf_base(p, "0123456789ABCDEF");

	return (len);
}
