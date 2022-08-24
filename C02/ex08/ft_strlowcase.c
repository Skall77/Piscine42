/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 22:10:50 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/12 22:28:03 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*temp;

	temp = str;
	if (*temp == '\0')
		return (temp);
	while (*temp)
	{
		if (!(*temp < 'A' || *temp > 'Z'))
			*temp = *temp + 32;
		temp++;
	}
	return (str);
}
