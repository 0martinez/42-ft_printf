#include "libftprintf.h"

static void	ft_aux(long n, int j, char *aux)
{
	if (n == 0)
		aux[j - 1] = '0';
	while (n != 0)
	{
		aux[j-- - 1] = (n % 10) + '0';
		n = n / 10;
	}
}

static char	*ft_itoa(int n)
{
	char	*aux;
	long	i;
	int		j;
	long	sb;

	j = 1;
	i = 1;
	sb = n;
	if (n <= 0 && j++ != -1)
		sb = sb * -1;
	while (i <= sb && j++ != -1)
		i = 10 * i;
	aux = (char *) malloc (sizeof(char) * (j));
	if (!aux)
		return (0);
	if (n < 0)
		aux[0] = '-';
	ft_aux(sb, j - 1, aux);
	aux[j - 1] = 0;
	return (aux);
}

void ft_putnbr(int num, int flg)
{
	char *str;

	if (flg == 1)
    {
        if (num < 0)
            num *= -1;
    }
    str = ft_itoa(num);
	ft_putstr(str);
}