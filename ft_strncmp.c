#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*s1 && *s2 && *s1 == *s2 && i < n)
	{
		s1++;
		s2++;
		i++;
	}
	return (*s1 - *s2);
}
/*int main(int ac, char **av)
{
	printf("%i\n",ft_strncmp(av[1],av[2],3));
	printf("%i\n", strncmp(av[1],av[2],3));
}*/
