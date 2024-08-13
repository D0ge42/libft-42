/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:27:04 by lorenzo           #+#    #+#             */
/*   Updated: 2024/08/13 18:27:05 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				s_len;
	unsigned int	i;
	char			*rs;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	i = 0;
	rs = (char *)malloc(sizeof (char) * (s_len + 1));
	if (rs == NULL)
		return (NULL);
	while (s[i])
	{
		rs[i] = f(i, s[i]);
		i++;
	}
	rs[i] = '\0';
	return (rs);
}
