/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:17:31 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/30 09:37:12 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
#include "ft_list.h"
//#include <stdio.h>

/*t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (elem == NULL)
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

void ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new;
	
	if (*begin_list)
	{
		new = ft_create_elem(data);
		new->next = *begin_list;
		*begin_list = new;
	}
	else
		*begin_list = ft_create_elem(data);
}*/

int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list -> next;
	}
	return (size);
}

//int	main(void)
//{
//	t_list	*elem;
//
//	elem = ft_create_elem("1547");
//	ft_list_push_front(&elem, "75785758");
//	ft_list_push_front(&elem, "848787848");
//	printf("%d", ft_list_size(elem));
//}
