/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:41:24 by omartine          #+#    #+#             */
/*   Updated: 2021/11/15 18:44:39 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);

int		ft_putnbr(int num);

int		ft_putunbr(unsigned long long num);

int		ft_putstr(char *str);

int		ft_strlen(char *str);

int		ft_putchar(char letter);

int		ft_hexa(unsigned long long num, int flg);

#endif
