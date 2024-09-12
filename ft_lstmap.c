/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:19:53 by lorenzo           #+#    #+#             */
/*   Updated: 2024/09/10 19:58:11 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new);
		lst = lst->next;
	}
	return (new_list);
}
/*t_list *ft_lstnew(void *content)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return NULL;
	new->content = content;
	new->next = NULL;
	return (new);
}

void ft_lstclear(t_list **new_list, void (*del )(void *))
{
	t_list *tmp;

	tmp = *new_list;
	while(*new_list && tmp)
	{
		tmp = (*new_list)->next;
		(*del)((*new_list)->content);
		(free)(*new_list);
		*new_list = tmp;
	}
	*new_list = NULL;
}

void ft_lstadd_back(t_list **new_list, t_list *new)
{
	if (!(*new_list))
	{
		*new_list = new;
		return ;
	}
	if (!(*new_list)->next)
	{
		(*new_list)->next = new;
		return ;
	}
	ft_lstadd_back(&(*new_list)->next, new);
}
*/
/*void *to_uppercase(void *data)
{
    char *str = (char *)data;
    for (int i = 0; str[i]; i++)
        str[i] = toupper(str[i]);
    return str;
}

void del_data(void *data)
{
	free(data);
}
int main()
{
	char *str = (char *)malloc(sizeof(char ) * 4);
	char *str1 = (char *)malloc(sizeof(char ) * 4);
	char *str2 = (char *)malloc(sizeof(char ) * 4);

	strcpy(str, "cia");
	strcpy(str1, "ciu");
	strcpy(str2, "cio");

	t_list *new = ft_lstnew(str);
	new->next = ft_lstnew(str1);
	new->next->next = ft_lstnew(str2);

	t_list *new2 = ft_lstmap(new, to_uppercase, del_data);
	t_list *temp;
	temp = new2;

	while(new2)
	{
		printf("%s ->", (char *)new2->content);
		new2  = new2->next;
	}
	//Testing memory leaks. Could've been done inside the while loop.
	free(temp);
	free(temp->next);
	free(temp->next->next);
	ft_lstclear(&new, del_data);
}*/
