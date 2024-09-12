/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:27:14 by lorenzo           #+#    #+#             */
/*   Updated: 2024/08/14 18:06:52 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	const char	*s2;

	s2 = s;
	while (*s)
		s++;
	return (s - s2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	size_t	s1len;
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	j = 0;
	s1len = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * (s1len + 1));
	if (!copy)
		return (NULL);
	while (ft_strchr(set, s1[i]) && i < (int)s1len)
		i++;
	j = i;
	while (s1[i])
		i++;
	while (ft_strchr(set, s1[i]))
		i--;
	while (j <= i)
		copy[k++] = s1[j++];
	copy[k] = '\0';
	return (copy);
}
