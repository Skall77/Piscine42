/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:10:01 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/15 20:04:33 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0u;
	while (*src != '\0')
	{
		if (i + 1 < size)
		{
			*dest = *src;
			dest++;
		}
			src++;
			i++;
	}
	*dest = '\0';
	return (i);
}
