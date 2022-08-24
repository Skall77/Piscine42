/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:08:02 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/21 21:42:52 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	backtracking(int **tab, int *input, int pos)
{
	int	i;

	i = 1;
	if (!(ft_ultimate_good_case(tab, input, pos)))
		return (0);
	pos++;
	if (pos == 16)
		return (1);
	while (i <= 4)
	{
		tab[pos / 4][pos % 4] = i;
		if (backtracking(tab, input, pos))
			return (1);
		i++;
	}
	return (0);
}

int	good_case(int **tab, int pos)
{
	int	i;
	int	j;
	int	k;

	i = pos / 4;
	j = pos % 4;
	k = 0;
	while (k < i)
	{
		if (tab[k][j] == tab[i][j])
			return (0);
		k++;
	}
	k = 0;
	while (k < j)
	{
		if (tab[i][k] == tab[i][j])
			return (0);
		k++;
	}
	return (1);
}

void	print_tab(int **tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(tab[i][j] + '0');
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
