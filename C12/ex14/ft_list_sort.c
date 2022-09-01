/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:26:54 by aaudevar          #+#    #+#             */
/*   Updated: 2022/09/01 14:11:29 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*list_ptr;
	t_list	*other_list_ptr;
	void	*data;
	int		swap;

	swap = 1;
	while (swap)
	{
		swap = 0;
		list_ptr = *begin_list;
		if (list_ptr == NULL)
			return ;
		while (list_ptr->next != NULL)
		{
			other_list_ptr = list_ptr->next;
			if ((*cmp)(list_ptr->data, other_list_ptr->data) > 0)
			{
				data = list_ptr->data;
				list_ptr->data = other_list_ptr->data;
				other_list_ptr->data = data;
				swap = 1;
			}
			list_ptr = list_ptr->next;
		}
	}
}
