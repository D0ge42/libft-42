/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:26:33 by lorenzo           #+#    #+#             */
/*   Updated: 2024/08/13 19:22:39 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i])
	{
		if ((str[i] != ' ' && (str[i] < 9 || str[i] > 13))
			&& ((str[i + 1] == ' ') || (str[i + 1] >= 9 && str[i + 1] <= 13)
				|| str[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static char	*ft_strncpy(char *dest, char *src, int n)
{
	int		i;
	char	*orig;

	i = 0;
	orig = dest;
	while (*src && i++ < n)
		*dest++ = *src++;
	*dest = '\0';
	return (orig);
}

char	*create_word(char *start, size_t length, char c)
{
	char	*word;

	word = (char *)malloc(sizeof(char) * (length + 2));
	if (!word)
		return (NULL);
	ft_strncpy(word, start, length);
	word[length] = c;
	word[length + 1] = '\0';
	return (word);
}

const char	*skip_whitespaces(const char *s)
{
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	return (s);
}

char	**ft_split(const char *s, char c)
{
	size_t		word_len;
	const char	*start;
	const char	*end;
	char		**words;
	int			i;

	i = 0;
	start = s;
	words = (char **)malloc((sizeof (char *) * (word_count(s) + 1)));
	if (!words)
		return (NULL);
	while (i < word_count(s))
	{
		start = skip_whitespaces(start);
		end = start;
		while (*end != ' ' && *end != '\t' && *end != '\n' && *end)
			end++;
		word_len = end - start;
		words[i++] = create_word((char *)start, word_len, c);
		start = end;
	}
	words[word_count(s) - 1][word_len] = '\0';
	words[word_count(s)] = NULL;
	return (words);
}
/*#include <stdio.h>
int main()
{
	char **str = ft_split("ciao come stai", ' ');
	int i = 0;
	while(str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}*/
