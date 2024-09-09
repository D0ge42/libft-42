/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:19:53 by lorenzo           #+#    #+#             */
/*   Updated: 2024/09/09 14:52:58 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return ;
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}
/*void free_node(void *data)
{
	free(data);
}

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

int main()
{
	t_list *new = ft_lstnew("ciao");
	t_list *new3 = (t_list *)malloc(sizeof(t_list));
	t_list *new2 = new;
	new->next = ft_lstnew("ciao1");
	new->next->next = ft_lstnew("ciao2");

	printf("List before function : ");
	t_list *temp = new;
	while (temp)
	{
		if (temp->next)
			printf("%s ->", (char *)temp->content);
		else
			 printf("%s", (char *)temp->content);
		temp = temp->next;
	}
	printf("\n");
	ft_lstdelone(new3, free_node);
}*/
