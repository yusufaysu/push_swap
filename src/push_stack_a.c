/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaysu <yaysu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:08:04 by yaysu             #+#    #+#             */
/*   Updated: 2022/06/20 13:12:08 by yaysu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	biggest_smallest(t_data	*data)
{
	int	biggest;
	int	smallest;
	int	i;

	biggest = 0;
	smallest = 0;
	i = 1;
	while (i < data->stk_b->len)
	{
		if (data->stk_b->number[i] > data->stk_b->number[biggest])
			biggest = i;
		if (data->stk_b->number[i] < data->stk_b->number[smallest])
			smallest = i;
		i++;
	}
	data->stk_b->b_index = biggest;
	data->stk_b->s_index = smallest;
}

void	conclusion(t_data *data, int	*sml_min_moves, int	*big_min_moves)
{
	int	i;
	int	repeat;
	int	is_ra;

	repeat = big_min_moves[0];
	is_ra = big_min_moves[1];
	if (sml_min_moves[0] <= big_min_moves[0])
	{
		repeat = sml_min_moves[0];
		is_ra = sml_min_moves[1];
	}
	i = 0;
	while (i++ < repeat)
	{
		if (is_ra)
			rb(data);
		else
			rrb(data);
	}
	pa(data);
	if (sml_min_moves[0] <= big_min_moves[0])
		ra(data);
}

void	push_to_stack_a(t_data	*data)
{
	int	*big_min_moves;
	int	*sml_min_moves;

	biggest_smallest(data);
	big_min_moves = malloc(2 * sizeof(int));
	sml_min_moves = malloc(2 * sizeof(int));
	big_min_moves[0] = data->stk_b->b_index;
	big_min_moves[1] = 1;
	if (data->stk_b->b_index > (data->stk_b->len - data->stk_b->b_index))
	{
		big_min_moves[0] = (data->stk_b->len - data->stk_b->b_index);
		big_min_moves[1] = 0;
	}
	sml_min_moves[0] = data->stk_b->s_index;
	sml_min_moves[1] = 1;
	if (data->stk_b->s_index > (data->stk_b->len - data->stk_b->s_index))
	{
		sml_min_moves[0] = (data->stk_b->len - data->stk_b->s_index);
		sml_min_moves[1] = 0;
	}
	conclusion(data, sml_min_moves, big_min_moves);
	free(big_min_moves);
	free(sml_min_moves);
}
