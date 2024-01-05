/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouille & aaudevard <marvin@42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:52:57 by ccouille          #+#    #+#             */
/*   Updated: 2022/08/30 20:26:53 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		map_error(void);
int		malloc_error(void);
int		fill_tab(char *stock, char *tab, int i);
//void	ft_putchar(char c);
//void	ft_putstr(char *str);
int		**malloc_error_double_pointer(void);

int		read_first_line(char *tab, int file);
int		check_table(int file, char *tab, int *dim);
int		init_read_map(char *path, char *tab, int *dim);
int		open_file(char *path);
int		close_file(int file);

//char	**read_input(void);
void	display_solution(char *tab, int *dim, int **matrix);
void	no_argument(void);
void	arguments(int argc, char **argv);

int		**find_solution(char *path, char *tab, int *dim);
int		**matrix_maker(char *tab, int file, int *dim, char *buf);
void	find_max(int *dim, int **matrix, int *max);
int		min_val(int a, int b, int c);
int		**maloc_matrix(int	*dim);

//void	free_split(char **str);
void	free_neo(int **tab, int *dim);
int		read_map_input(void);

//char	**ft_split(char *str, char *charset);
#endif
