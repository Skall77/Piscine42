/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:57:32 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/18 09:12:36 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_comb(void)
{
	int		c;
	int		d;
	int		u;

	c = 0;
	while (c < 8)
	{
		d = c + 1;
		while (d < 9)
		{
			u = d + 1;
			while (u < 10)
			{
				ft_putchar((char)c + '0');
				ft_putchar((char)d + '0');
				ft_putchar((char)u + '0');
				if ((c + d + u) < (7 + 8 + 9))
					write(1, ", ", 2);
				u++;
			}
			d++;
		}
		c++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
