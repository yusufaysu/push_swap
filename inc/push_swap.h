/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:04:11 by yaysu             #+#    #+#             */
/*   Updated: 2022/06/22 12:43:50 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <ctype.h>
# include <string.h>

typedef struct s_stack
{
	int	*number;
	int	len;
	int	b_index;
	int	s_index;
}	t_stack;

typedef struct s_data
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	t_stack	*stk_s;
	char	*o1;
	char	*o2;
	int		len;
}	t_data;

void		before_start(int argc, char *argv[], t_data *data);
void		print_error(char *str);
void		init_data(t_data *data);
void		ps_2(t_data *data);
void		ps_3(t_data *data, int is_3);
void		ps_5(t_data *data);
void		sa(t_data *data);
void		sb(t_data *data);
void		pb(t_data *data);
void		pa(t_data *data);
void		ra(t_data *data);
void		rb(t_data *data);
void		rra(t_data *data);
void		rrb(t_data *data);
void		make_index(t_data *data);
void		push_swap_advanced(t_data *data, int div);
void		push_to_stack_b(t_data *data, int div, int rotation);
void		set_splitters(t_data *data, int *min_max, int div, int rot);
void		push_to_stack_a(t_data *data);
void		biggest_smallest(t_data	*data);
void		conclusion(t_data *data, int	*sml_min_moves, int	*big_min_moves);
void		print_operation(t_data	*data, char	*str);
void		print_last(t_data *data);
void		free_everything(t_data *data);
void		free_array(char **arr);
void		check_data(int argc, char **argv);

int			stack_is_sorted(t_data *data);
int			check_input(char **argv);
int			check_input(char **argv);
int			operation_checker(t_data *data, char	*str);
int			operation_checker_tml(t_data	*data, char	*str1, char	*str2);
int			*nums_str_to_int(char **num, t_data *data);
int			*nums_argv_to_int(int argc, char **argv, t_data *data);

#endif
