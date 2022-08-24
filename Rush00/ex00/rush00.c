/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nserve <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:05:24 by nserve            #+#    #+#             */
/*   Updated: 2022/08/14 16:31:07 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_first_and_lastline(int x);
void	ft_middleline(int x);
void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	i;

	i = 0;
	if (x > 0 && y > 0)
	{
		if (y == 1)
			ft_first_and_lastline(x);
		else
		{
			ft_first_and_lastline(x);
			while (i++ < (y - 2))
			{
				ft_middleline(x);
			}
			ft_first_and_lastline(x);
		}
	}
}

void	ft_first_and_lastline(int x)
{	
	int	i;

	i = 0;
	while (++i <= x)
	{
		if (i == 1)
			ft_putchar('o');
		else
		{
			if (i < x)
				ft_putchar('-');
			else
				ft_putchar('o');
		}
	}
	ft_putchar('\n');
}

void	ft_middleline(int x)
{
	int	i;

	i = 0;
	while (i++ <= x)
	{
		if (i == 1 || i == x)
			ft_putchar('|');
		else
			ft_putchar(' ');
	}
	ft_putchar('\n');
}
