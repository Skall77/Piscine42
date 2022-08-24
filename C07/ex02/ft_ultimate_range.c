/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:19:14 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/22 10:31:13 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*nbs;
	int	i;
	int	size;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	nbs = malloc(sizeof(*nbs) * size);
	if (nbs == NULL)
		return (-1);
	while (i < size)
	{
		nbs[i] = min;
		i++;
		min++;
	}
	*range = nbs;
	return (i);
}
