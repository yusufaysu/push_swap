/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:02:45 by yaysu             #+#    #+#             */
/*   Updated: 2022/06/22 12:46:02 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	start_push_swap(t_data *data)
{
	make_index(data);
	if (stack_is_sorted(data) == 1)
	{
		if (data->len <= 2 && data->len > 1)
			ps_2(data);
		else if (data->len <= 3 && data->len > 1)
			ps_3(data, 1);
		else if (data->len <= 5 && data->len > 1)
			ps_5(data);
		else if (data->len <= 75 && data->len > 1)
			push_swap_advanced(data, 2);
		else if (data->len <= 150 && data->len > 1)
			push_swap_advanced(data, 3);
		else if (data->len <= 500 && data->len > 1)
			push_swap_advanced(data, 7);
	}
}

void	free_everything(t_data *data)
{
	free(data->stk_a->number);
	free(data->stk_b->number);
	free(data->stk_s->number);
	free(data->stk_a);
	free(data->stk_b);
	free(data->stk_s);
	free(data->o1);
	free(data->o2);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 1)
		exit(EXIT_FAILURE);
	before_start(argc, argv, &data);
	start_push_swap(&data);
	free_everything(&data);
}
