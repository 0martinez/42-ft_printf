/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:11:36 by omartine          #+#    #+#             */
/*   Updated: 2021/11/15 20:10:25 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	to_char(unsigned long long num, int flg)
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

static int	count_chars(unsigned long long num)
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

static int	run_reverse(int count, char *str)
{
	count--;
	while (count >= 0)
	{
		write(1, &str[count], 1);
		count--;
	}
	return (ft_strlen(str));
}

int	ft_hexa(unsigned long long num, int flg)
{
	int		count;
	char	*str;
	int		i;

	i = 0;
	if (num == 0)
		return (ft_putchar('0'));
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
	count = run_reverse(count, str);
	free(str);
	return (count);
}
