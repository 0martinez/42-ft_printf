#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

void ft_putnbr(int num, int flg);

void ft_putstr(char *str);

int ft_strlen(char *str);

void ft_putchar(char letter);

void ft_hexa(int num, int flg);

#endif
