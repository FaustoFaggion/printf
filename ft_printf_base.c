#include "ft_printf.h"
#include <stdio.h>
static int	ft_size(unsigned long int p, int base_size)
{
	int	i;

	i = 0;
	base_size = 16;
	if (!p)
		return (1);
	while (p)
	{
		p = p / base_size;
		i++;
	}
	return (i);
}

int	ft_printf_base(unsigned long int p, char *base)
{
	int		size_num;
	char	*num;
	int		base_size;
	int		i;

	base_size = 16;
	size_num = ft_size(p, base_size);
	num = (char *)malloc((size_num + 1) * sizeof(char));
	i = size_num;
	while(i > 0)
	{
		num[i - 1] = base[p % 16];
		p = p / 16;
		i--;
	}
	write(1, num, size_num);
	free(num);
	return (size_num);
}
