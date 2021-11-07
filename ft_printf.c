#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void ft_putchar(char letter)
{
    write(1, &letter, 1);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		ft_putchar(str[i]);
		i++;
	}
}

void dictionary(char c1, va_list ptr)
{
	//cspdiuxX %
	if (c1 == 'c')
		ft_putchar(va_arg(ptr, int));
	else if (c1 == 's')
		ft_putstr(va_arg(ptr, char *));
}

int ft_printf(const char *str, ...)
{
    int i;

	va_list ptr;
	va_start(ptr, str);
	i = 0;
	/*while (i < 3)
	{
		printf("%s\n", va_arg(ptr, char *));
		i++;
	} */ 
    while(str[i] != 0)
    {
        if (str[i] == '%')
		{
			i++;
			dictionary(str[i], ptr);
		}
		else
			write(1, &str[i], 1);
		i++;
    }
	va_end(ptr);
}

int main(void)
{
    ft_printf("aa %c ---- %s a", 'l', "mokoko");
	return 0;
}