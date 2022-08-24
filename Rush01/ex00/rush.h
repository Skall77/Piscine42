/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoulomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:04:38 by mcoulomb          #+#    #+#             */
/*   Updated: 2022/08/21 22:28:29 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
int		input_is_correct(char *str);
int		*input_to_tab(char *str);
int		**init_tab(void);
int		ft_strlen(char *str);
int		good_case(int **tab, int pos);
void	print_tab(int **tab);
int		ft_ultimate_good_case(int **tab, int *input, int pos);
int		check_col_up(int **tab, int *input, int pos);
int		check_col_down(int **tab, int *input, int pos);
int		check_row_left(int **tab, int *input, int pos);
int		check_row_right(int **tab, int *input, int pos);
int		backtracking(int **tab, int *input, int pos);
void	free_tab(int **tab);

#endif
