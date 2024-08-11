#include <unistd.h>
#include <stdlib.h>

int ft_strlen(const char *str)
{
	int	i;
	i = 0;
	while(str[i] != '\0')
		i++;
	return i;
}

int fstrlen(const char *str)
{
	int i = 0;
	int j = 0;
	while(str[i])
	{
		if(str[i] == ' ')
			j++;
		i++;
	}
	return i - j;
}

int word_count(const char *str)
{
	int words = 0;
	int i = 0;
	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while(str[i])
	{
		if((str[i] == ' ' || str[i] >= 9 && str[i] <= 13 || str[i+1] == '\0')
				&& (str[i + 1] != ' ') || str[i+1] <= 9 && str[i+1] >= 13)
			words++;
		i++;
	}
	return words;
}


//Se la stringa è "ciao come stai"
//la stringa dovrà dividersi in 3 sotto stringhe. ciao/0 come/0 /stai/0
//Come salvo ogni stringa ottenuta?
//Riempio l'array di stringhe con le strighe ottenute.
//Null termino l'array di stringhe.
char **ft_split(const char *s, char c)
{
	int	sep;
	int	total = 0;
	char	**words;
	int	i;
	int	j;

	i = 0;
	sep = word_count(s) - 1;
	//Allocate memory for entire string without spaces + separators + 1 for null terminator.
	words = (char **)malloc(sizeof(char) * (fstrlen(s) + sep + 1));
	//Obiettivo funzione : 
	while(words[i])
	{
		while(s[j])
		{
			words[i][j] = s[j];
			j++;
		}
		i++;
	}
	return words;
}


#include <stdio.h>
int main(int ac, char **av)
{
	char **str = ft_split(av[1],'-');
	printf("%s\n",str[0]);
}
		
