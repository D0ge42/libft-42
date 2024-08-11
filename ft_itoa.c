#include "libft.h"

static unsigned int	digit_count(int nb)
{
	unsigned int	digit_count;

	digit_count = 1;
	if (nb == -2147483648)
		return (10);
	if (nb < 0)
		nb *= -1;
	while (nb > 9)
	{
		nb /= 10;
		digit_count++;
	}
	return (digit_count);
}

static void	rarray(char *str)
{
	int		i;
	int		end;
	char	temp;

	i = 0;
	while (str[i] != '\0')
		i++;
	end = i - 1;
	if (str[0] == '-')
		i = 1;
	else
		i = 0;
	while (i < end)
	{
		temp = str[i];
		str[i] = str[end];
		str[end] = temp;
		i++;
		end--;
	}
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)malloc(sizeof (char) * (digit_count(n) + 2));
	if (!str)
		return (NULL);
	if (n == 0)
		return ("0");
	if (n == -2147483648)
		return ("-2147483648");
	while (n > 0 || n < 0)
	{
		if (n < 0)
		{
			str[i++] = '-';
			n *= -1;
		}
		str[i++] = n % 10 + '0';
		n /= 10;
	}
	rarray(str);
	str[i] = '\0';
	return (str);
}
