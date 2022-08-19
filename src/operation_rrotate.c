/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rrotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaysu <yaysu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:34:04 by yaysu             #+#    #+#             */
/*   Updated: 2022/06/14 18:49:37 by yaysu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra(t_data *data)
{
	int	temp;
	int	i;

	if (data->stk_a->len > 1)
	{
		i = data->stk_a->len - 1;
		temp = data->stk_a->number[i];
		while (i > 0)
		{
			data->stk_a->number[i] = data->stk_a->number[i - 1];
			i--;
		}
		data->stk_a->number[0] = temp;
	}
	print_operation(data, "rra\n");
}

void	rrb(t_data *data)
{
	int	temp;
	int	i;

	if (data->stk_b->len > 1)
	{
		i = data->stk_b->len - 1;
		temp = data->stk_b->number[i];
		while (i > 0)
		{
			data->stk_b->number[i] = data->stk_b->number[i - 1];
			i--;
		}
		data->stk_b->number[0] = temp;
	}
	print_operation(data, "rrb\n");
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
	print_operation(data, "rrr\n");
}
