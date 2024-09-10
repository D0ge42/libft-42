/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:19:53 by lorenzo           #+#    #+#             */
/*   Updated: 2024/09/10 19:58:31 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	if (!(*lst)->next)
	{
		(*lst)->next = new;
		return ;
	}
	ft_lstadd_back(&(*lst)->next, new);
}
/*t_list	*ft_lstnew(void *content)
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
	t_list **new = (t_list **)malloc(sizeof(t_list *) * 3);
	*new = ft_lstnew("ciao");
	(*new)->next = ft_lstnew("42");
	(*new)->next->next = ft_lstnew("45");

	t_list *created = ft_lstnew("43");
	ft_lstadd_back(new,created);
	while((*new)->next)
		*new = (*new)->next;
	printf("last data of last element %s\n", (char *)(*new)->content);
	printf("Pointing %p\n", (*new)->next);
}*/
