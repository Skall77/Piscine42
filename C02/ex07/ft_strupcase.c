/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:34:23 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/12 22:19:14 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*temp;

	temp = str;
	if (*temp == '\0')
		return (temp);
	while (*temp)
	{
		if (!(*temp < 'a' || *temp > 'z'))
			*temp = *temp - 32;
		temp++;
	}
	return (str);
}
