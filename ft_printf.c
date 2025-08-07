/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:09:42 by buehara           #+#    #+#             */
/*   Updated: 2025/08/07 18:44:28 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *s, ...)
{
	va_list	list;
	//char 	*str;

	va_start(list, s);

	ft_putstr_fd((char *)s, 1);

	va_end(list);

	return (ft_strlen(s));
}

#include <stdio.h>
int	main(void)
{
	char *str = "This is a string";
	int	org, new;

	org = printf("\n\tMy function: \n");

	new = ft_printf("\n\tMy function: \n");

	printf("Return :\n\tOriginal %d | My Function %d\n", org, new);

	return (0);
}
