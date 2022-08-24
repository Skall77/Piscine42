/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_good_case.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:28:19 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/21 21:46:33 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	check_col_up(int **tab, int *input, int pos)
{
	int	j;
	int	k;
	int	building;
	int	count;

	j = pos % 4;
	building = 0;
	count = 0;
	k = 0;
	while (k < 4)
	{
		if (tab[k][j] > building)
		{
			building = tab[k][j];
			count++;
		}
		k++;
	}
	if (input[pos % 4 + 0 * 4] != count)
		return (0);
	return (1);
}

int	check_col_down(int **tab, int *input, int pos)
{
	int	j;
	int	k;
	int	building;
	int	count;

	j = pos % 4;
	building = 0;
	count = 0;
	k = 3;
	while (k >= 0)
	{
		if (tab[k][j] > building)
		{
			building = tab[k][j];
			count++;
		}
		k--;
	}
	if (input[pos % 4 + 1 * 4] != count)
		return (0);
	return (1);
}

int	check_row_left(int **tab, int *input, int pos)
{
	int	i;
	int	k;
	int	building;
	int	count;

	i = pos / 4;
	building = 0;
	count = 0;
	k = 0;
	while (k < 4)
	{
		if (tab[i][k] > building)
		{
			building = tab[i][k];
			count++;
		}
		k++;
	}
	if (input[pos / 4 + 2 * 4] != count)
		return (0);
	return (1);
}

int	check_row_right(int **tab, int *input, int pos)
{
	int	i;
	int	k;
	int	building;
	int	count;

	i = pos / 4;
	building = 0;
	count = 0;
	k = 3;
	while (k >= 0)
	{
		if (tab[i][k] > building)
		{
			building = tab[i][k];
			count++;
		}
		k--;
	}
	if (input[pos / 4 + 3 * 4] != count)
		return (0);
	return (1);
}

int	ft_ultimate_good_case(int **tab, int *input, int pos)
{
	int	i;
	int	j;

	i = pos / 4;
	j = pos % 4;
	if (!(good_case(tab, pos)))
		return (0);
	if (i == 3)
	{
		if (!(check_col_up(tab, input, pos)))
			return (0);
		if (!(check_col_down(tab, input, pos)))
			return (0);
	}
	if (j == 3)
	{
		if ((!check_row_left(tab, input, pos)))
			return (0);
		if (!(check_row_right(tab, input, pos)))
			return (0);
	}
	return (1);
}
