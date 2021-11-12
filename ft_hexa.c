/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:11:36 by omartine          #+#    #+#             */
/*   Updated: 2021/11/12 18:59:45 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	to_char(long num, int flg)
{
	char	hexa;

	if (num > 9)
	{
		if (flg == 1)
			hexa = 'A' + (num - 10);
		else
			hexa = 'a' + (num - 10);
	}
	else
		hexa = '0' + num;
	return (hexa);
}

static int	count_chars(long num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

int	ft_hexa(long num, int flg)
{
	int		count;
	char	*str;
	int		i;

	i = 0;
	if (num == 0)
		return (ft_putchar('0'));
	if (num < 0)
		num = 4294967296 - (num * -1);
	count = count_chars(num);
	str = (char *) malloc(sizeof(char) * count + 1);
	if (!str)
		return (0);
	str[count] = 0;
	while (num != 0)
	{
		str[i] = to_char(num % 16, flg);
		num = num / 16;
		i++;
	}
	count--;
	while (count >= 0)
	{
		write(1, &str[count], 1);
		count--;
	}
	count = ft_strlen(str);
	free(str);
	return (count);
}
/*
int	main(void)
{
	ft_hexa(-1, 1);
	printf("\n%X", -1);
	return 0;
}*/
