/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:54:53 by aaudevar          #+#    #+#             */
/*   Updated: 2022/09/01 11:14:19 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

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

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new;

	if (*begin_list)
	{
	new = ft_create_elem(data);
	new->next = *begin_list;
	*begin_list = new;
	}
	else
		*begin_list = ft_create_elem(data);
}

void ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *new;

	new = *begin_list;
	if (new)
	{
		while (new->next)
			new = new->next;
		new->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}

void    ft_list_sort(t_list **begin_list, int (*cmp)())
{
    t_list  *list_ptr;
    t_list  *other_list_ptr;
    void    *data;
    int     swap;

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


int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	main(void)
{
	t_list *begin_list;
	begin_list= malloc(sizeof(t_list));
	int a = 1254;
	int b = 54848;
	int c = 548787;
	int	d = 1;
	void *pa = &a;
	void *pb = &b;
	void *pc = &c;
	void *pd = &d;
	begin_list = ft_create_elem(pa);
	begin_list->next= ft_create_elem(pb);
	ft_list_push_back(&begin_list, pd);
	ft_list_push_front(&begin_list, pc);
	ft_list_sort(&begin_list, &ft_strcmp);
	while(begin_list != NULL)
	{
		printf("%d\n",*(int *)begin_list->data);
		begin_list = begin_list->next;
	}
}

