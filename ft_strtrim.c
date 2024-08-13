/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:27:14 by lorenzo           #+#    #+#             */
/*   Updated: 2024/08/13 18:27:15 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	size_t	s1len;
	int		i;
	int		k;

	i = 0;
	k = 0;
	s1len = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * (s1len + 1));
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		if (!(ft_strchr(set, s1[i])))
			copy[k++] = s1[i];
		i++;
	}
	copy[k] = '\0';
	return (copy);
}
