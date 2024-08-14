/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:35:48 by lorenzo           #+#    #+#             */
/*   Updated: 2024/08/14 17:27:36 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static unsigned int	digit_count(int nb)
{
	unsigned int	digits_count;

	digits_count = 0;
	if (nb == 0)
		return (1);
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		digits_count = 1;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		digits_count++;
	}
	return (digits_count);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	digits;

	digits = digit_count(n);
	str = (char *)malloc(sizeof(char) * (digits + 2));
	if (!str)
		return (NULL);
	str[digits] = '\0';
	if (n == -2147483648)
		return ("-2147483648");
	if (n == 0)
		return ("0");
	while (n != 0)
	{
		if (n < 0)
		{
			str[0] = '-';
			n *= -1;
		}
		str[--digits] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
