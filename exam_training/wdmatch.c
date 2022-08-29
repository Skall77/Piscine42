/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:44:46 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/25 15:22:16 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str);
void	ft_strprint(char *str);

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		int j = 0;
		int count = 0;

		while(argv[1][i])
		{
			while(argv[2][j])
			{
				if (argv[1][i] == argv[2][j])
				{
					count ++;
					break;
				}

				j++;
			}
			i++;
		}
		if (count == ft_strlen(argv[1]))
			ft_strprint(argv[1]);
	}
	write(1, "\n", 1);
}

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_strprint(char *str)
{
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}


