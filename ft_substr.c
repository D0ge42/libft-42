/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:28:18 by lorenzo           #+#    #+#             */
/*   Updated: 2024/08/13 18:28:19 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*rstring;
	unsigned int	i;

	i = 0;
	rstring = (char *)malloc(sizeof(char) * (len + 1));
	if (!rstring)
		return (NULL);
	while (len--)
		rstring[i++] = s[start++];
	rstring[i] = '\0';
	return (rstring);
}
/*int main()
{
	printf("%s\n", ft_substr("ciaocoglioni", 4, 9));
}*/	
