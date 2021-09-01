#include "libftprintf.h"

int	ft_def_base(char *base)
{
	int	def_base;
	int	index;

	def_base = 0;
	while (base[def_base] != '\0')
	{
		if (base[def_base] == '+' || base[def_base] == '-')
		{
			write (1, "Não é permitido os caracteres '+' e '-' na base.", 49);
			return (0);
		}
		index = def_base + 1;
		while (base[index] != '\0')
		{
			if (base[def_base] == base[index])
			{
				write (1, "Não é permitido caracteres iguais na base.", 44);
				return (0);
			}
			index++;
		}
		def_base++;
	}
	return (def_base);
}

int	ft_verify_base(int def_base)
{
	int	index;

	index = 0;
	if (def_base == 1 || def_base == '\0')
	{
		write (1, "Favor colocar uma base maior ou igual a 2.", 41);
		return (0);
	}
	return (def_base);
}

int	ft_count_nbr(int nbr, int def_base)
{
	int	nbr_nbr;
	int	count_nbr;

	nbr_nbr = nbr;
	count_nbr = 0;
	while (nbr_nbr >= def_base)
	{
		nbr_nbr = nbr_nbr / def_base;
		count_nbr++;
	}
	return (count_nbr);
}

int	ft_chage_base(int def_base, int nbr, char *base)
{
	int				index;
	unsigned long	count_nbr;
	char			*num;

	count_nbr = ft_count_nbr(nbr, def_base);
	num = (char *)malloc(count_nbr * sizeof(char));
	while (nbr >= def_base)
	{
		index = nbr - ((nbr / def_base) * def_base);
		num[count_nbr] = base[index];
		nbr = nbr / def_base;
		count_nbr--;
	}
	if (nbr >= 0 && nbr < def_base)
	{
		index = nbr;
		num[count_nbr] = base[index];
	}
	write (1, num, count_nbr + 1);
	free(num);
	return (count_nbr);
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	unsigned long	def_base;
	unsigned long	nbr_nbr;
	unsigned long	index;

	def_base = ft_def_base(base);
	ft_verify_base(def_base);
	return (ft_chage_base(def_base, nbr, base) + 1);
}
