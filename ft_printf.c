#include <stdio.h>
#include <stdarg.h>



int ft_printf(const char *a, ...)
{
	int		i;
	va_list	ptr;


	i = 0;
	while (a[i] != '\0')
	{
		if (a[i] == '%')
		{
			va_start(ptr, )
		}
		printf("%c", a[i]);
		i++;
	}
	return(0);

}

int main(void)
{
	char	str1[] = "22";
	//int	str2 = 1;


	ft_printf("Fausto%", str1 );
	return (0);
}
