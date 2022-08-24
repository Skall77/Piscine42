/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:08:02 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/21 22:29:21 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	**init_tab(void)
{
	int	**tab;
	int	row;
	int	col;
	int	i;

	row = 4;
	col = 4;
	i = 0;
	tab = malloc(row * sizeof(int *));
	if (tab == NULL)
		return (NULL);
	while (i < row)
	{
		tab[i] = malloc(col * sizeof(int));
		if (tab == NULL)
			return (NULL);
		i++;
	}
	return (tab);
}

void	free_tab(int **tab)
{
	int	row;
	int	i;

	row = 4;
	i = 0;
	while (i < row)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free (tab);
	tab = NULL;
}
