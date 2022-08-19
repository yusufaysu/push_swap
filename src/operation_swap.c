/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaysu <yaysu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:12:44 by yaysu             #+#    #+#             */
/*   Updated: 2022/06/14 18:49:29 by yaysu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_data *data)
{
	int	temp;

	if (data->stk_a->len > 1)
	{
		temp = data->stk_a->number[0];
		data->stk_a->number[0] = data->stk_a->number[1];
		data->stk_a->number[1] = temp;
	}
	print_operation(data, "sa\n");
}

void	sb(t_data *data)
{
	int	temp;

	if (data->stk_b->len > 1)
	{
		temp = data->stk_b->number[0];
		data->stk_b->number[0] = data->stk_b->number[1];
		data->stk_b->number[1] = temp;
	}
	print_operation(data, "sb\n");
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
	print_operation(data, "ss\n");
}

void	check_data(int argc, char **argv)
{
	if (argc <= 1)
		print_error("Error\n");
	if (ft_strlen(argv[1]) == '\0')
		exit(EXIT_SUCCESS);
}
