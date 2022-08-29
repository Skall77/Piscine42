/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:28:34 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/24 16:44:32 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *ft_rev_print (char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i > -1)
	{
		write(1, &str[i], 1);
		i--;
	}
	write(1, "\n", 1);
	return(str);
}

int main(void)
{
	ft_rev_print("zaz");
	ft_rev_print("dub0 a POIL");
	ft_rev_print("");
}
