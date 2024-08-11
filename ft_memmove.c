#include "libft.h"

void	*memmove(void *dest, const void *src, size_t n)
{
	char	*cdest;
	char	*csrc;

	cdest = (char *)dest;
	csrc = (char *)src;
	if (!cdest && !csrc)
		return (0);
	if (dest <= src)
	{
		while (n--)
			*cdest++ = *csrc++;
	}
	else if (dest > src)
	{
		cdest += n - 1;
		csrc += n - 1;
		while (n--)
			*cdest-- = *csrc--;
	}
	return (dest);
}
/*#include <stdio.h>
int main()
{
		char buffer[20] = "ciao sono lorenzo";
		char temp[20];
		printf("%s\n", (char*)memmove(temp+2,buffer,18));
		return 0;
}*/
