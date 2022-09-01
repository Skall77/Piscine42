/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:54:30 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/31 18:03:23 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <unistd.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*prev;
	t_list	*temp;
	t_list	*next;

	prev = NULL;
	temp = *begin_list;
	next = NULL;
	while (temp != NULL)
	{
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	*begin_list = prev;
}
