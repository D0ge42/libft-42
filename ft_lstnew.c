/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:19:53 by lorenzo           #+#    #+#             */
/*   Updated: 2024/09/09 14:53:53 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*int main()
{
	t_list *new_first;
	new_first->content = "4";
	new_first->next =  ft_lstnew("5");
	printf("First node %s, second node %s\n",(char *)new_first->content,
	(char *)new_first->next->content);
	printf("Second node is pointing %p\n", new_first->next->next);
}
*/
