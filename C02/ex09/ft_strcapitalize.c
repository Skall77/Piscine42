/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:00:42 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/14 11:28:51 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	ft_isnum(char c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

int	ft_isalnum(char c)
{
	if (ft_isalpha(c) || ft_isnum(c))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] = str[i] -32;
	while (str[i] != '\0')
		i++;
	j = 1;
	while (j < i)
	{
		if ((str[j] >= 'a' && str[j] <= 'z') && !(ft_isalnum(str[j - 1])))
			str[j] = str[j] - 32;
		else if (((str[j] >= 'A' && str[j] <= 'Z')) && ft_isalnum(str[j - 1]))
			str[j] = str[j] + 32;
		j++;
	}
	return (str);
}
