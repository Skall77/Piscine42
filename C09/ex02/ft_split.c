/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:09:09 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/24 16:07:25 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && is_sep(str[i], charset))
			i++;
		if (str[i] != '\0' && !(is_sep(str[i], charset)))
			words++;
		while (str[i] != '\0' && !(is_sep(str[i], charset)))
			i++;
	}
	return (words);
}

void	copy_word(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (!(is_sep(src[i], charset)))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	put_word_in_split(char **split, char *str, char *charset)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (is_sep(str[i], charset))
			i++;
		else
		{
			j = 0;
			while (!is_sep(str[i + j], charset))
				j++;
			split[k] = malloc(sizeof(char) * (j + 1));
			copy_word(split[k], str + i, charset);
			i = i + j;
			k++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		size;

	size = count_words(str, charset);
	split = malloc(sizeof(char *) * size + 1);
	split[size] = 0;
	put_word_in_split(split, str, charset);
	return (split);
}
