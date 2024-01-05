/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avg_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouille & aaudevard <marvin@42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:04:13 by ccouille          #+#    #+#             */
/*   Updated: 2022/08/30 20:43:26 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	read_first_line(char *tab, int file)
{
	char	buf[1];
	char	stock[14];
	int		i;

	i = -1;
	if (read(file, buf, 1) == 0)
		return (map_error());
	while ((++i <= 14) && (buf[0] != '\n'))
	{
		stock[i] = buf[0];
		if (read(file, buf, 1) == 0)
			return (map_error());
	}
	if ((i < 3) || (i > 14))
		return (map_error());
	i = fill_tab(stock, tab, i);
	while (--i >= 0)
	{
		if ((stock[i] < '0') || (stock[i] > '9'))
			return (map_error());
	}
	if ((tab[0] == tab[1]) || (tab[0] == tab[2]) || (tab[1] == tab[2]))
		return (map_error());
	return (1);
}

int	init_read_map(char *path, char *tab, int *dim)
{
	int	file;

	file = open_file(path);
	if (file == -1)
		return (0);
	if (read_first_line(tab, file) == -1)
		return (0);
	if (check_table(file, tab, dim) == -1)
		return (0);
	if (close_file(file) == -1)
		return (0);
	return (1);
}

int	check_table(int file, char *tab, int *dim)
{
	char	buf[2];
	int		i;

	i = 0;
	dim[0] = 0;
	dim[1] = 0;
	while (read(file, buf, 1) != 0)
	{
		if (buf[0] == '\n')
		{	
			if (((dim[1] - i != 0) && (dim[1] != 0)) || (i == 0))
				return (map_error());
			else
				dim[1] = i;
			i = -1;
			dim[0]++;
		}
		else if ((buf[0] != tab[0]) && (buf[0] != tab[1]))
			return (map_error());
		buf[1] = buf[0];
		i++;
	}
	if ((dim[0] == 0) || (buf[1] != '\n'))
		return (map_error());
	return (1);
}

int	open_file(char *path)
{
	int	file;

	file = open(path, O_RDONLY);
	if (file == -1)
		return (map_error());
	return (file);
}

int	close_file(int file)
{
	if (close(file) == -1)
		return (map_error());
	return (1);
}

/*

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

int	put_word_in_split(char **split, char *str, char *charset)
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
			if (split[k] == NULL)
				return (0);
			copy_word(split[k], str + i, charset);
			i = i + j;
			k++;
		}
	}
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		size;

	size = count_words(str, charset);
	split = malloc(sizeof(char *) * size + 1);
	if (split == NULL)
		return (NULL);
	split[size] = 0;
	if (put_word_in_split(split, str, charset) == 0)
		return (NULL);
	return (split);
}
*/
