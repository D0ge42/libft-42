#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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
		if ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13)
			|| ((str[i + 1] == '\0') && ((str[i + 1] != ' ')
					|| (str[i + 1] <= 9 && str[i + 1] >= 13))))
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

char	**ft_split(const char *s, char c)
{
	size_t		word_len;
	const char	*start;
	const char	*end;
	char		**words;
	int			i;

	i = 0;
	start = s;
	words = (char **)malloc((sizeof (char *) * (word_count(s)) + 1));
	while (i < word_count(s))
	{
		while (*start == ' ' || (*start >= 9 && *start <= 13))
			start++;
		end = start;
		while (*end != ' ' && *end != '\t')
			end++;
		word_len = end - start;
		words[i] = (char *)malloc(sizeof (char) * (word_len + 1));
		ft_strncpy(words[i], (char *)start, word_len);
		words[i][word_len] = c;
		start = end;
		i++;
	}
	return (words);
}
/*int main()
{
	int i = 0;
	char **str = ft_split("A BOM BA ZZA",'+');
	while(str[i])
		printf("%s", str[i++]);
}*/
