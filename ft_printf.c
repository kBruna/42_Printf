/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:09:42 by buehara           #+#    #+#             */
/*   Updated: 2025/08/10 18:57:33 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putstr(char *s, int *count)
{
	char	*null;

	null = "(null)";
	if (s == NULL)
	{
		(*count) += (int)write(1, null, 6);
		return ;
	}
	while (*s)
	{
		(*count) += (int)write(1, s, 1);
		s++;
	}
}

static void	ft_putnbr(long n, int t_char, int *count)
{
	long	nbr;
	char	minus;

	nbr = n;
	minus = '-';
	if (nbr < 0 && t_char == 1)
	{
		nbr *= -1;
		(*count) += (int)write(1, &minus, 1);
	}
	if (nbr > 9)
		ft_putnbr((nbr / 10), 0, count);
	nbr = nbr % 10 + '0';
	(*count) += (int)write(1, &nbr, 1);
}

static void	ft_puthex(unsigned long nbr, char x, int *count)
{
	char	*hex_nbr;
	char	hex_end;
	char	value;

	value = x;
	if (value - 'p' == 0)
	{
		if (nbr == 0)
		{
			(*count) += (int)write(1, "(nil)", 5);
			return ;
		}
		(*count) += (int)write(1, "0x", 2);
		value = 'x';
	}
	if (value - 'x' == 0)
		hex_nbr = "0123456789abcdef";
	else
		hex_nbr = "0123456789ABCDEF";
	if (nbr > 15)
		ft_puthex((nbr / 16), value, count);
	hex_end = hex_nbr[(nbr % 16)];
	(*count) += (int)write(1, &hex_end, 1);
}

static int	*ft_printflags(const char s, int *count, va_list list)
{
	char	percent;
	char	pt_char;

	percent = '%';
	if ((s - 'd') == 0 || (s - 'i') == 0)
		ft_putnbr(va_arg(list, int), 1, count);
	else if (s - 'c' == 0)
	{
		pt_char = (char)va_arg(list, int);
		(*count) += (int)write(1, &pt_char, 1);
	}
	else if (s - 's' == 0)
		ft_putstr(va_arg(list, char *), count);
	else if (s - '%' == 0)
		(*count) += (int)write(1, &percent, 1);
	else if (s - 'u' == 0)
		ft_putnbr(va_arg(list, unsigned int), 0, count);
	else if (s - 'x' == 0 || s - 'X' == 0)
		ft_puthex(va_arg(list, unsigned int), s, count);
	else if (s - 'p' == 0)
		ft_puthex(va_arg(list, unsigned long), s, count);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		count;

	count = 0;
	va_start(list, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			ft_printflags(*s, &count, list);
		}
		else
			count += (int)write(1, s, 1);
		s++;
	}
	va_end(list);
	return (count);
}
