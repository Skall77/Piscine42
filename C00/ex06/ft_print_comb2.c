/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:47:29 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/18 09:12:15 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);
void	ft_print2int(int a, int b);
void	ft_putchar(char c);

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a <= 98)
	{
		while (b <= 99)
		{
			ft_print2int(a, b);
			b++;
		}
		b = a + 2;
		a++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print2int(int a, int b)
{
	int	first_number_a;
	int	second_number_a;
	int	first_number_b;
	int	second_number_b;

	first_number_a = a / 10;
	second_number_a = a % 10;
	first_number_b = b / 10;
	second_number_b = b % 10;
	ft_putchar(first_number_a + '0');
	ft_putchar(second_number_a + '0');
	ft_putchar(' ');
	ft_putchar(first_number_b + '0');
	ft_putchar(second_number_b + '0');
	if (first_number_a < 9 || second_number_a < 8)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}
