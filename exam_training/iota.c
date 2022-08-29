/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iota.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:40:28 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/25 17:05:55 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	nblen(int nb);

char *ft_iota(int nb)
{
	long	n;
	int		i;
	char *str;

	n = nb;
	i = nblen(n);
	str = malloc(sizeof(char) * i + 1);
	str[i] = '\0';
	i--;
	if (n == 0)
		str[0] = '0';
	if ( n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while ( n > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return(str);
}


int	nblen(int nb)
{
	int len;
	len = 0;
	if (nb < 0)
	{
		len ++;
		nb = nb * -1;
	}
	while( nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return(len);
}

int main(void)
{
	printf("%s", ft_iota(0));
}
