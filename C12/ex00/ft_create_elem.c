/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:33:16 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/28 19:34:34 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_create_elem(void *data)
{
	t_list	*begin_list;

	begin_list = malloc(sizeof(t_list);
	if (begin_list == NULL)
		return (NULL);
	begin_list->data = data;
	begin_list->next = NULL;
	return (begin_list);
}

