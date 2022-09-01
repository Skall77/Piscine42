/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:22:09 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/30 14:57:02 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (elem == NULL)
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*begin_list;

	if (size <= 0)
		return (NULL);
	begin_list = ft_create_elem((void *) strs[size - 1]);
	begin_list->next = ft_list_push_strs(size - 1, strs);
	return (begin_list);
}
