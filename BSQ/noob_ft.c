/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noob_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouille & aaudevard <marvin@42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:00:03 by ccouille          #+#    #+#             */
/*   Updated: 2022/08/30 20:40:45 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
*/
int	fill_tab(char *stock, char *tab, int i)
{
	tab[2] = stock[--i];
	tab[1] = stock[--i];
	tab[0] = stock[--i];
	return (i);
}

int	map_error(void)
{
	write(2, "map error\n", 10);
	return (-1);
}

int	malloc_error(void)
{
	return (0);
}

int	**malloc_error_double_pointer(void)
{
	return (0);
}
