/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:09:42 by buehara           #+#    #+#             */
/*   Updated: 2025/08/08 21:16:13 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return ((int)write(1, &c, 1));
}

void ft_putstr(char *s, int *count)
{
	while (*s)
	{
		(*count) += ft_putchar(*s);
		s++;
	}
}

void	ft_putnbr(long n, int t_char, int *count)
{
	long	nbr;

	nbr = n;
	if (nbr < 0 && t_char == 1)
	{
		nbr *= -1;
		(*count) += ft_putchar('-');
	}
	if (nbr > 9)
		ft_putnbr((nbr / 10), 0, count);
	(*count) += ft_putchar((nbr % 10) + '0');
}

void	ft_putnsg(unsigned int n, int *count)
{
	if (n > 9)
		ft_putnsg(n / 10, count);
	(*count) += ft_putchar(n % 10 + '0');
}



int	*ft_printflags(const char s, int *count, va_list list)
{
	if (!ft_strncmp(&s, "d", 1) || !ft_strncmp(&s, "i", 1))
		ft_putnbr(va_arg(list, int), 1, count);
	else if (!ft_strncmp(&s, "c", 1))
		(*count) += ft_putchar((char)va_arg(list, int));
	else if (!ft_strncmp(&s, "s", 1))
		ft_putstr(va_arg(list, char *), count);
	else if (!ft_strncmp(&s, "%", 1))
		(*count) += ft_putchar('%');
	else if (!ft_strncmp(&s, "u", 1))
		ft_putnbr(va_arg(list, unsigned int), 0, count);
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
			count += ft_putchar(*s);
		s++;
	}
	va_end(list);
	return (count);
}
/*
#include <stdio.h>
int	main(void)
{
//	char 	*str = "This is a string";
	int		org = -123; 
	int		new = -123;
	char	d	= 'z';
	unsigned int minus = -5;

	org = printf("\n\tOg function: %d %i %% %c %u\n", org, org, d, minus);

	new = ft_printf("\n\tMy function: %d %i %% %c %u\n", new, new, d, minus);

	printf("Return :\n\tOriginal %d | My Function %d\n", org, new);

	return (0);
}*/
