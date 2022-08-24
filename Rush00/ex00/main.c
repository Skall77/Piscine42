/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nserve <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:10:45 by nserve            #+#    #+#             */
/*   Updated: 2022/08/14 16:05:50 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);
void	ft_first_and_lasline(int x, char begin, char end);
void	ft_middleline(int x);
void	ft_putchar(char c);

int	main(void)
{
	rush(0, 0);
	rush(1, 1);
	rush(2, 2);
	rush(5, 1);
	rush(1, 5);
	rush(5, 3);
	rush(3, 5);
	rush(4, 4);
	rush(80, 80);
}
