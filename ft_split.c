#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(const char *str)
{
	int	i;
	i = 0;
	while(str[i] != '\0')
		i++;
	return i;
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

char *ft_strncpy(char *dest, char *src, int n)
{
	int i = 0;
	char *orig = dest;
	while(*src && i < n)
	{
		*dest++ = *src++;
		i++;
	}
	*dest = '\0';
	return orig;
}

//s = stringa da dividere in più sotto stringhe.
//**words sarà un array di stringhe. --> Dove andremo a mettere le sottostringhe.
//Primo step. Malloc per le parole totali.
//Secondo step. Inizializzare le parole a NULL? perchè?
//Ciclare le varie parole per calcolarne la lunghezza e allocando memoria per ognuna di esse.

char **ft_split(const char *s, char c)
{
	int	num_words;
	size_t	word_len;
	const char 	*start = s;
	const char	*end;
	char	**words;
	int	i;

	i = 0;
	num_words = word_count(s);
	//Allocate memory for the whole string + sep + 1 for null terminator.
	words = (char **)malloc((sizeof(char *) * (num_words) + 1));
	printf("%li\n",sizeof(char*) * (num_words) + 1);
	i = 0;
	while (i < num_words)
	{
		while(*start == ' ' || *start == '\t')
			start++;
		end = start; //Primo carattere trovato, ora aumentiamo end fino alla fine della parola.
		while(*end != ' ' && *end != '\t')
			end++; //Trovo la fine della parola.
		word_len = end - start; // --> lunghezza parola.
		words[i] = (char*)malloc(sizeof(char) * (word_len +1)); //Allocato spazio per la prima parola.
		ft_strncpy(words[i],(char*)start,word_len);
		while( i < num_words - 1)
		start = end;
		i++;
	}
	i = 0;
	return words;
}




int main(int ac, char **av)
{
	char **str = ft_split("ciao come state ragazzi",'+');
	printf("%s %s %s  %s\n", str[0], str[1], str[2], str[3]);
}

