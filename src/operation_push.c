/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaysu <yaysu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:26:23 by yaysu             #+#    #+#             */
/*   Updated: 2022/06/14 18:48:16 by yaysu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pa(t_data *data)
{
	int	i;
	int	num;

	if (data->stk_b->len > 0)
	{
		num = data->stk_b->number[0];
		i = 1;
		while (data->stk_b->len > i)
		{
			data->stk_b->number[i - 1] = data->stk_b->number[i];
			i++;
		}
		data->stk_b->len--;
		i = data->stk_a->len;
		while (i > 0)
		{
			data->stk_a->number[i] = data->stk_a->number[i - 1];
			i--;
		}
		data->stk_a->number[0] = num;
		data->stk_a->len++;
	}
	print_operation(data, "pa\n");
}

void	pb(t_data *data)
{
	int	i;
	int	num;

	if (data->stk_a->len > 0)
	{
		num = data->stk_a->number[0];
		i = 1;
		while (data->stk_a->len > i)
		{
			data->stk_a->number[i - 1] = data->stk_a->number[i];
			i++;
		}
		data->stk_a->len--;
		i = data->stk_b->len;
		while (i > 0)
		{
			data->stk_b->number[i] = data->stk_b->number[i - 1];
			i--;
		}
		data->stk_b->number[0] = num;
		data->stk_b->len++;
	}
	print_operation(data, "pb\n");
}
