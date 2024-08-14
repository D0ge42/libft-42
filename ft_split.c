/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:16:51 by lorenzo           #+#    #+#             */
/*   Updated: 2024/08/14 15:14:20 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

static int	words_count(char const *str, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		if ((str[i] == c && (str[i + 1] != c)) || str[i + 1] == '\0')
			words++;
		i++;
	}
	return (words);
}

char	*ft_strncpy(char *dest, char *src, int len, char c)
{
	int		i;
	char	*orig;

	orig = dest;
	i = 0;
	while (i < len)
	{
		if (*src != c)
			*dest++ = *src++;
		i++;
	}
	*dest = '\0';
	return (orig);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*start;
	char	*end;
	int		i;

	i = 0;
	split = (char **)malloc(sizeof(char *) * (words_count(s, c) + 1));
	if (!split)
		return (NULL);
	start = (char *)s;
	while (i < words_count(s, c))
	{
		while (*start == c)
			start++;
		end = start;
		while (*end != c && *end)
			end++;
		end++;
		split[i] = (char *)malloc(sizeof(char) * (end - start + 1));
		ft_strncpy(split[i++], start, end - start, c);
		start = end;
	}
	split[i] = 0;
	return (split);
}
