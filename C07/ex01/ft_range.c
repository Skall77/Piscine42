/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:19:03 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/18 13:34:26 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*nbs;
	int	i;
	int	size;

	i = 0;
	if (min >= max)
		return (NULL);
	size = max - min;
	nbs = malloc(sizeof(*nbs) * size);
	if (nbs == NULL)
		return (NULL);
	while (i < size)
	{
		nbs[i] = min;
		i++;
		min++;
	}
	return (nbs);
}
