/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoulomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 10:03:38 by mcoulomb          #+#    #+#             */
/*   Updated: 2022/08/21 20:50:06 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	input_is_correct(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) != 31)
		return (0);
	while (str[i] != '\0')
	{
		if ('1' <= str[i] && str[i] <= '4')
		{
			if (i == 30)
				return (1);
			else if (str[i + 1] == ' ')
				i += 2;
			else
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

int	*input_to_tab(char *str)
{
	int	i;
	int	j;
	int	*newtab;

	newtab = malloc(sizeof(int) * 16);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			newtab[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	return (newtab);
}
