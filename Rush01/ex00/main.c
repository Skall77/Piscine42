/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoulomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:14:34 by mcoulomb          #+#    #+#             */
/*   Updated: 2022/08/21 22:37:52 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	main(int argc, char *argv[])
{
	int	**tab;
	int	i;
	int	*input;

	if (argc == 2 && input_is_correct(argv[1]))
	{
		i = 1;
		tab = init_tab();
		input = input_to_tab(argv[1]);
		while (i <= 4)
		{
			tab[0][0] = i;
			if (backtracking(tab, input, 0))
			{
				print_tab(tab);
				return (0);
			}
			i++;
		}
	}
	free_tab(tab);
	free(input);
	write(1, "Error\n", 6);
	return (1);
}
