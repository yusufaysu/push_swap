/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaysu <yaysu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:05:38 by yaysu             #+#    #+#             */
/*   Updated: 2022/06/20 13:06:18 by yaysu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_splitters(t_data *data, int *min_max, int div, int rot)
{
	min_max[0] = (data->len - (data->len / div)) - (rot * (data->len / div));
	if ((rot + 1) - (div - (data->len % div)) > 0)
		min_max[0] -= (rot + 1) - (div - (data->len % div));
	min_max[1] = (data->len - 1) - (rot * (data->len / div));
	if (rot - (div - (data->len % div)) > 0)
		min_max[1] -= rot -(div - (data->len % div));
}

void	push_to_stack_b(t_data *data, int div, int rotation)
{
	int	*min_max;
	int	count;

	min_max = malloc(2 * sizeof(int));
	set_splitters(data, min_max, div, rotation);
	count = 0;
	while (count < (min_max[1] - min_max[0]) + 1)
	{
		if (data->stk_a->number[0] >= min_max[0]
			&& data->stk_a->number[0] <= min_max[1])
		{
			pb(data);
			count++;
		}
		else
			ra(data);
	}
	free(min_max);
}

void	final_touch(t_data	*data)
{
	int	i;
	int	repeat;

	i = 0;
	if (data->stk_a->number[0]
		< (data->stk_a->len - data->stk_a->number[0]))
	{
		repeat = data->stk_a->number[0];
		while (i++ < repeat)
		{
			rra(data);
		}
	}
	else
	{
		repeat = data->stk_a->len - data->stk_a->number[0];
		while (i++ < repeat)
			ra(data);
	}
	if (data->o1[0] != '\0')
		ft_putstr_fd(data->o1, 1);
	if (data->o2[0] != '\0')
		ft_putstr_fd(data->o2, 1);
}

void	push_swap_advanced(t_data *data, int div)
{
	int	i;

	i = 0;
	while (i < div)
	{
		push_to_stack_b(data, div, i);
		while (data->stk_b->len > 0)
			push_to_stack_a(data);
		i++;
	}
	final_touch(data);
}
