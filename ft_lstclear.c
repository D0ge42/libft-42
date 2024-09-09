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
#include <string.h>

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp = *lst;

	while (*lst && tmp)
	{
		tmp = (*lst)->next;
		(*del)((*lst)->content);
		*lst = tmp;
		free(*lst);
	}
	free(*lst);
	*lst = 0;
}

void free_node(void *data)
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
	char *str0 = (char *)malloc(sizeof(char ) * 5);
	char *str1 = (char *)malloc(sizeof(char ) * 5);
	char *str2 = (char *)malloc(sizeof(char ) * 5);

	strcpy(str0, "1234");
	strcpy(str1, "4567");
	strcpy(str2, "6789");

	t_list *new = ft_lstnew(str0);
	new->next = ft_lstnew(str1);
	new->next->next = ft_lstnew(str2);

	t_list *temp = new;
	while(temp)
	{
		if (temp->next)
			printf("%s ->", (char *)temp->content);
		else
			printf("%s", (char *)temp->content);
		temp = temp->next;
	}
	printf("\n");
	ft_lstclear(&new, free_node);
}
