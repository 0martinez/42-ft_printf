/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:06:52 by omartine          #+#    #+#             */
/*   Updated: 2021/11/15 20:10:10 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static char	*ft_itoa(unsigned long long n)
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

int	ft_putunbr(unsigned long long num)
{
	char	*str;
	int		count;

	count = 0;
	str = ft_itoa(num);
	count = ft_putstr(str);
	free(str);
	return (count);
}
