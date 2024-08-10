#include "libft.h"

void	*memcpy(void *dest, const void *src, size_t n)
{
	void				*origdest;
	const unsigned char	*s;
	unsigned char		*d;

	origdest = dest;
	s = (const unsigned char *) src;
	d = (unsigned char *) dest;
	while (n--)
		*d++ = *s++;
	return (origdest);
}
