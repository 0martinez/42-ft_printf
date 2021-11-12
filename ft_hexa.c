/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:11:36 by omartine          #+#    #+#             */
/*   Updated: 2021/11/10 20:34:33 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	to_char(int num, int flg)
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

static int	count_chars(int num)
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

static int negative(long long int num)
{
	num = 4294967295 - num;
	return (num);
}

static int extras(long long int num)
{
	int	i;

	i = 0;
	if (num == 9223372036854775807)
	{
		i = ft_strlen("9223372036854775807");
		write(1, &"9223372036854775807", i);
		return (i);
	}
	else
	{
		i = ft_strlen("-9223372036854775807");
		write(1, &"-9223372036854775807", i);
		return (i);
	}
	return (0);
}

int	ft_hexa(long long int num, int flg)
{
	int		count;
	char	*str;
	int		i;

	i = 0;
	if (num < 0)
		num = negative(num);
	if (num == 9223372036854775807 || num == -9223372036854775807)
		return (extras(num));
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

int main(void)
{
	ft_hexa(922337203, 1);
	return 0;
}
