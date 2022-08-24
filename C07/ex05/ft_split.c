/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:36:51 by aaudevar          #+#    #+#             */
/*   Updated: 2022/08/23 19:38:01 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen2(char *str, char *charset);
char	**ft_split(char *str, char *charset);
int		is_charset(char c, char *charset);
int		count_words(char *str, char *charset);
char	*cut_word(char *str, char *charset);

int	ft_strlen2(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !is_charset(str[i], charset))
		i++;
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		words;
	int		i;

	i = 0;
	words = count_words(str, charset);
	split = malloc((words + 1) * (sizeof(char *)));
	while (*str != '\0')
	{	
		while (*str != '\0' && is_charset(*str, charset))
			str++;
		if (*str != '\0')
		{
			split[i] = cut_word(str, charset);
			i++;
		}
		while (*str != '\0' && !is_charset(*str, charset))
			str++;
	}
	split[i] = malloc(sizeof(char));
	return (split);
}

char	*cut_word(char *str, char *charset)
{
	int		i;
	char	*word;
	int		size;

	i = 0;
	size = ft_strlen2(str, charset);
	word = malloc(sizeof(char) * (size + 1));
	while (i < size)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && is_charset(str[i], charset))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !is_charset(str[i], charset))
			i++;
	}
	return (count);
}
