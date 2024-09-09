/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:19:53 by lorenzo           #+#    #+#             */
/*   Updated: 2024/09/09 14:53:06 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*int main()
{
	t_list **lst;
	lst = (t_list **)malloc(sizeof(t_list *) * 3);
	*lst = (t_list *)malloc(sizeof(t_list));
	(*lst)->content = "1";
	(*lst)->next = NULL;
	t_list *new;
	new->content = "789";

	ft_lstadd_front(lst,new);
	printf("First content of first node %s\n", (char *)(*lst)->content);
	printf("Pointing %p\n", (*lst)->next);
	printf("Value pointed %s\n", (char *)(*lst)->next->content);
}*/
