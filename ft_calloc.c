#include "libft.h"
#include <stdlib.h>

void	*calloc(size_t count, size_t size)
{
	size_t	total;
	void	*p;

	total = count * size;
	p = malloc (total);
	if (!p)
		return (NULL);
	ft_bzero(p, total);
	return (p);
}
