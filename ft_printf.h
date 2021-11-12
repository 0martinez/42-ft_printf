/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:41:24 by omartine          #+#    #+#             */
/*   Updated: 2021/11/10 20:32:13 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);

int		ft_putnbr(int num, int flg);

int		ft_putstr(char *str);

int		ft_strlen(char *str);

int		ft_putchar(char letter);

int		ft_hexa(long long int num, int flg);

#endif
