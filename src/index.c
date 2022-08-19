/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:40:53 by yaysu             #+#    #+#             */
/*   Updated: 2022/06/22 12:28:12 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*copy_arr(t_data *data)
{
	int	*new_arr;
	int	i;

	i = 0;
	new_arr = malloc(data->len * sizeof(int));
	while (i < data->len)
	{
		new_arr[i] = data->stk_a->number[i];
		i++;
	}
	data->stk_s->len = data->stk_a->len;
	return (new_arr);
}

void	sort_a(t_data *data)
{
	int	i;
	int	temp;

	data->stk_s->number = copy_arr(data);
	i = 1;
	while (i < data->len)
	{
		if (i != 0 && data->stk_s->number[i] < data->stk_s->number[i - 1])
		{
			temp = data->stk_s->number[i];
			data->stk_s->number[i] = data->stk_s->number[i - 1];
			data->stk_s->number[i - 1] = temp;
			i -= 2;
		}
		i++;
	}
}

int	*make_index_arr(int *numbers, int *s_numbers, int arr_len)
{
	int	i;
	int	j;
	int	*index_arr;

	i = 0;
	index_arr = malloc(arr_len * sizeof(int));
	while (i < arr_len)
	{
		j = 0;
		while (j < arr_len)
		{
			if (numbers[i] == s_numbers[j])
			{
				index_arr[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (index_arr);
}

void	make_index(t_data *data)
{
	int	*holder;

	sort_a(data);
	holder = data->stk_a->number;
	data->stk_a->number = make_index_arr
		(data->stk_a->number, data->stk_s->number, data->len);
	free(holder);
}
