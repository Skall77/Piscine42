/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:56:19 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/30 11:14:35 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*last;

	if (begin_list)
	{
		while (begin_list)
		{
			last = begin_list;
			begin_list = begin_list->next;
		}
		return (last);
	}
	return (begin_list);
}
