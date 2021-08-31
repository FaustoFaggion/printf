#include "libftprintf.h"

void ft_putnbr_base(unsigned long nbr, char *base)
{
	unsigned long	def_base;
	unsigned long	nbr_nbr;
	unsigned long	count_nbr;
	unsigned long	count_nbr_write;
	unsigned long	index;
	char			*num;

	def_base = 0;
	while(base[def_base] != '\0')
	{
		if (base[def_base] == '+' || base[def_base] == '-')
		{
			write (1, "Não é permitido os caracteres '+' e '-' na base.", 49);
			return;
		}
		index = def_base + 1;
		while (base[index] != '\0')
		{
			if (base[def_base] == base[index])
			{
				write (1, "Não é permitido caracteres iguais na base.", 44);
				return;
			}
			index++;
		}
		def_base++;
	}
	index = 0;
	if (def_base == 1 || def_base == '\0')
	{
		write (1, "Favor colocar uma base maior ou igual a 2.", 41);
		return;
	}
	nbr_nbr = nbr;
	count_nbr = 0;
	while (nbr_nbr >= def_base)
		{
			nbr_nbr = nbr_nbr / def_base;
			count_nbr++;
		}
	count_nbr_write = count_nbr + 1;
	num = (char *)malloc(count_nbr_write * sizeof(char));
	nbr_nbr = nbr;
	while (nbr_nbr >= def_base)
	{
		index = nbr_nbr - ((nbr_nbr / def_base) * def_base);
		num[count_nbr] = base[index];
		nbr_nbr = nbr_nbr / def_base;
		count_nbr--;
	}
	if(nbr_nbr >= 0 && nbr_nbr < def_base)
	{
		index = nbr_nbr;
		num[count_nbr] = base[index];
	}
	write (1, num, count_nbr_write);
	free(num);
}
