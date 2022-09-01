/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:22:34 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/31 15:53:13 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*ret;

	i = 0;
	ret = begin_list;
	while (ret != NULL)
	{
		if (i == nbr)
			return (ret);
		ret = ret->next;
		i++;
	}
	return (NULL);
}
