/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaysu <yaysu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:18:32 by yaysu             #+#    #+#             */
/*   Updated: 2022/06/14 18:48:56 by yaysu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_data *data)
{
	int	temp;
	int	i;

	if (data->stk_a->len > 1)
	{
		i = 0;
		temp = data->stk_a->number[i];
		while (i < data->stk_a->len - 1)
		{
			data->stk_a->number[i] = data->stk_a->number[i + 1];
			i++;
		}
		data->stk_a->number[data->stk_a->len - 1] = temp;
	}
	print_operation(data, "ra\n");
}

void	rb(t_data *data)
{
	int	temp;
	int	i;

	if (data->stk_b->len > 1)
	{
		i = 0;
		temp = data->stk_b->number[i];
		while (i < data->stk_b->len - 1)
		{
			data->stk_b->number[i] = data->stk_b->number[i + 1];
			i++;
		}
		data->stk_b->number[data->stk_b->len - 1] = temp;
	}
	print_operation(data, "rb\n");
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
	print_operation(data, "rr\n");
}
