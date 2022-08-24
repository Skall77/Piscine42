/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:36:07 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/17 17:20:56 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int		ft_error(char *base);
int		ft_isspace_or_minus(char c);
int		ft_char_in_str(char c, char *str);
int		ft_int_base(char c, char *str);

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		neg;
	long	atoi;
	int		s_base;

	if (ft_error(base))
		return (0);
	i = 0;
	neg = 1;
	atoi = 0;
	s_base = 0;
	while (base[s_base])
		s_base++;
	while (ft_isspace_or_minus(str[i]))
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (ft_char_in_str(str[i], base))
	{
		atoi = atoi * s_base + ft_int_base(str[i], base);
		i++;
	}
	return (atoi * neg);
}

int	ft_isspace_or_minus(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13) || c == '-' || c == '+')
		return (1);
	return (0);
}

int	ft_error(char *base)
{
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	i = 0;
	while (base[i] != '\0')
	{
		if (ft_isspace_or_minus(base[i]))
			return (1);
		j = 1;
		while (base[i + j] != '\0')
		{
			if (base[i] == base[i + j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_char_in_str(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_int_base(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	main(void)
{
	char str[]=" -----++-243ab";
	printf("%d",ft_atoi_base(str,"0123456789"));
}
