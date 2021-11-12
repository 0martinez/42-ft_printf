/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:41:41 by omartine          #+#    #+#             */
/*   Updated: 2021/11/12 19:02:32 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dictionary(char c1, va_list ptr)
{
	int	count;

	count = 0;
	if (c1 == 'c')
		count = ft_putchar(va_arg(ptr, int));
	else if (c1 == 's')
		count = ft_putstr(va_arg(ptr, char *));
	else if (c1 == 'p')
		printf("xd");
	else if (c1 == 'd' || c1 == 'i')
		count = ft_putnbr(va_arg(ptr, int), 0);
	else if (c1 == 'u')
		count = ft_putnbr(va_arg(ptr, unsigned int), 1);
	else if (c1 == 'x')
		count = ft_hexa(va_arg(ptr, long), 0);
	else if (c1 == 'X')
		count = ft_hexa(va_arg(ptr, long), 1);
	else if (c1 == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ptr;
	int		count;

	count = 0;
	va_start(ptr, str);
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			i++;
			count += dictionary(str[i], ptr);
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	va_end(ptr);
	return (count);
}
/*
int	main(void)
{
	int i = 0;
	int j = 0;

	i = ft_printf("%c---%s---%d---%i---%u---%x---%X---%%---%d", 'a', "kakakaka", 22, 42, 42, 42949672, 1234, 22);
	printf("  +++%d+++\n", i);
	j = printf("%c---%s---%d---%i---%u---%x---%X---%%---%d", 'a', "kakakaka", 22, 42, 42, 1 * -1, 1234, 22);
	printf("  +++%d+++", j);
	return 0;
}*/
