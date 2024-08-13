/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:22:33 by lorenzo           #+#    #+#             */
/*   Updated: 2024/08/13 18:22:34 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*j;
	char	*start;
	int		len;

	len = ft_strlen(s);
	j = (char *)malloc(sizeof (char) * len + 1);
	if (!j)
		return (NULL);
	start = j;
	while (*s)
		*j++ = *s++;
	*j = '\0';
	return (start);
}
/*int main(int ac, char **av)
{
	printf("Indirizzo memoria primo argomento %p\n",av[1]);
	char *str = ft_strdup(av[1]);
	printf("Indirizzo memoria stringa copiata %p\n", str);
}*/
