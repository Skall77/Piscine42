/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 07:45:39 by aaudevar          #+#    #+#             */
/*   Updated: 2022/09/01 08:33:15 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
void (*free_fct)(void *))
{
	t_list	*list_ptr;
	t_list	*temp;

	list_ptr = *begin_list;
	if (list_ptr != NULL && (*cmp)(list_ptr->data, data_ref) == 0)
	{
		*begin_list = list_ptr->next;
		(*free_fct)(list_ptr->data);
		free(list_ptr);
		list_ptr = *begin_list;
		temp = *begin_list;
	}
	while (list_ptr != NULL)
	{
		if ((*cmp)(list_ptr->data, data_ref) == 0)
		{
			temp->next = list_ptr->next;
			(*free_fct)(list_ptr->data);
			free(list_ptr);
			list_ptr = temp;
		}
		temp = list_ptr;
		list_ptr = list_ptr->next;
	}
}
