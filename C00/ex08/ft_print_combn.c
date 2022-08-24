/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:49:48 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/18 10:31:32 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_number(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
	if (tab[0] != 10 - n)
		write(1, ", ", 2);
}

void	ft_print_combn(int n)
{
	int	tab_nb[9];
	int	i;

	i = 0;
	while (i < n)
	{
		tab_nb[i] = i;
		i++;
	}
	ft_print_number(tab_nb, n);
	i = n - 1;
	while (tab_nb[0] < 10 - n)
	{
		while (tab_nb[i] == 10 - n + i)
			i--;
		tab_nb[i]++;
		while (i != n - 1)
		{
			tab_nb[i + 1] = tab_nb[i] + 1;
			i++;
		}
		ft_print_number(tab_nb, n);
	}
}
