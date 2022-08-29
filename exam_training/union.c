/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:58:35 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/25 14:31:34 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	isnt_doubles(char c, char *str, int pos);

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		int j = 0;
		while(argv[1][i])
		{
			if(isnt_doubles(argv[1][i], argv[1], i))
				write(1,&argv[1][i],1);
			i++;
		}
		i = 0;
		while(argv[2][j])
		{
			if(isnt_doubles(argv[2][j], argv[1], i) && isnt_doubles(argv[2][j], argv[2], j))
				write(1,&argv[2][j],1);
			i++;
			j++;
		}
				
	
	}
	write(1,"\n", 1);
}
int isnt_doubles(char c, char *str, int pos)
{
	int i;
	i = 0;
	while (i < pos)
	{
		if(str[i] == c)
			return (0);
		i++;
	}
	return (1);
}
	
