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

int	ft_hexa(long num, int flg)
{
	int		count;
	char	*str;
	int		i;

	i = 0;
	if (num < 0)
		num = num * -1;
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
int main(void)
{
	ft_hexa(1234, 1);
	return 0;
}*/
