/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:09:07 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/23 11:47:40 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_ultimate_size(int size, char **strs, char *sep)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < size)
	{
		n = n + ft_strlen(strs[i]);
		n = n + ft_strlen(sep);
		i++;
	}
	n = n - ft_strlen(sep) + 1;
	return (n);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;
	char	*copy;

	if (size == 0)
		return (malloc(sizeof(char)));
	i = 0;
	str = malloc((sizeof(char)) * ft_ultimate_size(size, strs, sep));
	copy = str;
	if (copy == NULL)
		return (0);
	while (i < size)
	{
		ft_strcpy(copy, strs[i]);
		copy = copy + ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(copy, sep);
			copy = copy + ft_strlen(sep);
		}
		i++;
	}
	*copy = '\0';
	return (str);
}
