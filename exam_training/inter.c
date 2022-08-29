/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:53:56 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/25 10:56:31 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_dup (char c, char *str, int pos);

int	main(int argc, char **argv)
{	
	if (argc == 3)
	{
		int i = 0;
		int j;
		while(argv[1][i])
		{
			j = 0;
			while (argv[2][j])
			{
				if(argv[1][i] == argv[2][j])
				{
					if(is_dup(argv[1][i], argv[1], i))
					{
						write(1, &argv[1][i], 1);
						break;
					}
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}

int	is_dup (char c, char *str, int pos)
{
	int i;
	i = 0;
	while(i < pos)
	{
		if(str[i] == c)
			return (0);
		i++;
	}
return(1);
}

