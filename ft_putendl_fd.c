#include "libft.h"

void	ft_putendl_ft(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
	write(fd, "\n", 1);
}
