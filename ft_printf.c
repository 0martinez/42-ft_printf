#include "libftprintf.h"

va_list dictionary(char c1, va_list ptr)
{
	//cspdiuxX %
	if (c1 == 'c')
		ft_putchar(va_arg(ptr, int));
	else if (c1 == 's')
		ft_putstr(va_arg(ptr, char *));
	else if (c1 == 'p')
		printf("xd");
	else if (c1 == 'd' || c1 == 'i')
		ft_putnbr(va_arg(ptr, int), 0);
	else if (c1 == 'u')
		ft_putnbr(va_arg(ptr, int), 1);
	else if (c1 == 'x')
		ft_hexa(va_arg(ptr, int), 0);
	else if (c1 == 'X')
		ft_hexa(va_arg(ptr, int), 1);
	else if (c1 == '%')
		ft_putchar('%');
	return ptr;

}

int ft_printf(const char *str, ...)
{
    int i;

	va_list ptr;
	va_start(ptr, str);
	i = 0;
    while(str[i] != 0)
    {
        if (str[i] == '%')
		{
			i++;
			ptr = dictionary(str[i], ptr);
		}
		else
			write(1, &str[i], 1);
		i++;
    }
	va_end(ptr);
	return 0;
}

int main(void)
{
    ft_printf("%c---%s---%d---%i---%u---%x---%X---%%---%d", 'a', "kakakaka", "22", 42, -42, 1234, 1234, 22);
	printf("\n%c---%s---%d---%i---%u---%x---%X---%%---%d", 'a', "kakakaka", "22", 42, -42, 1234, 1234, 22);
	return 0;
}