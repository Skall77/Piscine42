/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:40:27 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/22 14:23:07 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
int		ft_strlen(char *str);
int		nblen(int nb, char *base);
void	ft_convert(int n, char *base, char *converted);
int		ft_error(char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*converted;
	int		n;
	int		size;

	if (ft_error(base_from) || ft_error(base_to))
		return (0);
	n = ft_atoi_base(nbr, base_from);
	size = nblen(n, base_to);
	converted = malloc(sizeof(char) * (size + 1));
	if (converted == NULL)
		return (NULL);
	ft_convert(n, base_to, converted);
	converted[size] = '\0';
	return (converted);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	nblen(int nb, char *base)
{
	int		lenght;
	int		lenbase;
	long	n;

	lenght = 0;
	lenbase = ft_strlen(base);
	if (nb < 0)
	{
		n = nb * -1;
		lenght++;
	}
	else
		n = nb;
	while (n >= lenbase)
	{
		n = n / lenbase;
		lenght++;
	}
	lenght++;
	return (lenght);
}

void	ft_convert(int n, char *base, char *converted)
{
	int		lenbase;
	int		lenght;
	int		i;
	long	nb;

	lenbase = ft_strlen(base);
	lenght = nblen(n, base);
	nb = n;
	i = 0;
	converted[lenght + 1] = '\0';
	if (nb < 0)
	{
		converted[0] = '-';
		nb = nb * -1;
		i = 1;
	}
	lenght--;
	while (nb >= lenbase)
	{
		converted[lenght] = base[nb % lenbase];
		nb = nb / lenbase;
		lenght--;
	}
	if (nb < lenbase)
		converted[i] = base[nb];
}
