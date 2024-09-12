/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:23:56 by lorenzo           #+#    #+#             */
/*   Updated: 2024/08/13 18:23:57 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*s2;
	char		*last_occurence;

	s2 = s;
	last_occurence = NULL;
	while (*s)
		s++;
	if (c == '\0')
		return ((char *)s);
	while (s-- > s2)
	{
		if (*s == c)
			return (last_occurence = (char *)s);
	}
	return (last_occurence);
}
