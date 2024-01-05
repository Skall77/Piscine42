/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouille aaudevard <marvin@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:00:35 by ccouille          #+#    #+#             */
/*   Updated: 2022/08/30 20:54:25 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	**maloc_matrix(int *dim)
{
	int	i;
	int	**matrix;

	i = -1;
	matrix = malloc(dim[0] * sizeof(int *));
	if (matrix == 0)
		return (malloc_error_double_pointer());
	while (++i < dim[0])
	{
		matrix[i] = malloc((dim[1]) * sizeof(int));
		if (matrix[i] == 0)
			return (malloc_error_double_pointer());
	}
	return (matrix);
}

int	**matrix_maker(char *tab, int file, int *dim, char *buf)
{
	int		j;
	int		i;
	int		**m;

	m = maloc_matrix(dim);
	if (m == NULL)
		return (0);
	j = 0;
	i = 0;
	while ((read(file, buf, 1) != 0) && ((dim[0]) * (dim[1]) > i * j))
	{
		if (buf[0] == tab[1])
			m[i][j] = 0;
		else if ((buf[0] == tab[0]) && ((i != 0) && (j != 0)))
			m[i][j] = min_val(m[i - 1][j], m[i][j - 1], m[i - 1][j - 1]);
		else if (buf[0] == tab[0])
			m[i][j] = 1;
		else if (buf[0] == '\n')
		{
			i++;
			j = -1;
		}
		j++;
	}
	return (m);
}

int	**find_solution(char *path, char *tab, int *dim)
{
	char	buf[1];
	int		file;
	int		**matrix;

	file = open_file(path);
	if (file == -1)
		return (0);
	read(file, buf, 1);
	while (buf[0] != '\n')
		read(file, buf, 1);
	matrix = matrix_maker(tab, file, dim, buf);
	if (matrix == 0)
		return (0);
	if (close_file(file) == -1)
		return (0);
	return (matrix);
}

void	find_max(int *dim, int **matrix, int *max)
{
	int	value;
	int	i;
	int	j;

	i = -1;
	j = -1;
	value = -1;
	while (++i < dim[0])
	{
		while (++j < dim[1])
		{
			if (matrix[i][j] > value)
			{
				value = matrix[i][j];
				max[0] = i - value + 1;
				max[1] = j - value + 1;
				max[2] = i;
				max[3] = j;
			}
		}
		j = 0;
	}
}

int	min_val(int a, int b, int c)
{
	if ((a <= b) && (a <= c))
		return (a + 1);
	if ((b <= a) && (b <= c))
		return (b + 1);
	return (c + 1);
}
