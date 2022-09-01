/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:03:30 by aaudevar          #+#    #+#             */
/*   Updated: 2022/09/01 09:25:37 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*list_ptr;
	t_list	*prev;

	list_ptr = *begin_list1;
	while (list_ptr != NULL)
	{
		prev = list_ptr;
		list_ptr = list_ptr->next;
	}
	prev->next = begin_list2;
}
