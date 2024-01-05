/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouille & aaudevard <marvin@42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:52:22 by ccouille          #+#    #+#             */
/*   Updated: 2022/08/30 20:38:15 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
char	**read_input(void)
{
	char	input[255];
	char	*str;
	char	c;
	int		i;
	char	**split;

	i = 0;
	while (read(0, &c, 1) && c != '\n')
		input[i++] = c;
	input[i] = '\0';
	str = malloc(i * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (input[i])
	{
		str[i] = input[i];
		i++;
	}
	str[i] = '\0';
	split = ft_split(str, " ");
	free(str);
	return (split);
}
*/
int	read_map_input(void)
{
	char	c;
	int		fd;

	fd = open("./map_input.txt", O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		return (map_error());
	while ((read(0, &c, 1)) && (c != 4))
	{
		if (c == 4)
			break ;
		write(fd, &c, 1);
	}
	if (close_file(fd) == -1)
		return (map_error());
	return (1);
}

void	display_solution(char *tab, int *dim, int **matrix)
{
	int	j;
	int	i;
	int	max[4];

	i = 0;
	j = 0;
	find_max(dim, matrix, max);
	while (i < dim[0])
	{
		while (j < dim[1])
		{
			if (matrix[i][j] == 0)
				write(1, &tab[1], 1);
			else if (((i >= max[0]) && (i <= max[2]))
				&& ((j >= max[1]) && (j <= max[3])))
				write(1, &tab[2], 1);
			else
				write(1, &tab[0], 1);
			j++;
		}
		i++;
		j = 0;
		write(1, "\n", 1);
	}
}

/*void	no_argument(void)
{
	int		i;
	int		**matrix;
	char	tab[3];
	int		dim[2];
	char	**split;

	i = -1;
	split = read_input();
	while (split[++i])
	{
		if (init_read_map(split[i], tab, dim) == 0)
			continue ;
		matrix = find_solution(split[i], tab, dim);
		if (matrix == 0)
			continue ;
		display_solution(tab, dim, matrix);
		free_neo(matrix, dim);
	}
	free_split(split);
}
*/
void	no_argument(void)
{
	int		**matrix;
	char	tab[3];
	int		dim[2];
	int		fd;

	if (read_map_input() == -1)
		return ;
	if (init_read_map("map_input.txt", tab, dim) == 0)
		return ;
	matrix = find_solution("map_input.txt", tab, dim);
	if (matrix == 0)
		return ;
	display_solution(tab, dim, matrix);
	fd = open("./map_input.txt", O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		write(2, "map error\n", 10);
	else if (close_file(fd) == -1)
		write(2, "map error\n", 10);
	free_neo(matrix, dim);
}

void	arguments(int argc, char **argv)
{
	int		i;
	int		**matrix;
	char	tab[3];
	int		dim[2];

	i = 0;
	while (++i < argc)
	{
		tab[0] = '\n';
		tab[1] = '\n';
		tab[2] = '\n';
		if (init_read_map(argv[i], tab, dim) == 0)
			continue ;
		matrix = find_solution(argv[i], tab, dim);
		if (matrix == 0)
			continue ;
		display_solution(tab, dim, matrix);
		free_neo(matrix, dim);
	}
}
