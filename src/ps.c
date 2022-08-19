/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaysu <yaysu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:13:30 by yaysu             #+#    #+#             */
/*   Updated: 2022/06/14 18:47:20 by yaysu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ps_2(t_data *data)
{
	if (data->stk_a->number[0] > data->stk_a->number[1])
		sa(data);
	print_last(data);
}

void	assign_lmb(t_data *data, int *lmb)
{
	int	i;

	i = 1;
	lmb[0] = 0;
	lmb[1] = 0;
	lmb[2] = 0;
	while (i < 3)
	{
		if (data->stk_a->number[i] < data->stk_a->number[lmb[0]])
			lmb[0] = i;
		if (data->stk_a->number[i] > data->stk_a->number[lmb[2]])
			lmb[2] = i;
		i++;
	}
	lmb[1] = 3 - (lmb[2] + lmb[0]);
}

void	cases(t_data *data, int *lmb)
{
	if (lmb[0] == 1 && lmb[1] == 0 && lmb[2] == 2)
		sa(data);
	else if (lmb[0] == 2 && lmb[1] == 1 && lmb[2] == 0)
	{
		sa(data);
		rra(data);
	}
	else if (lmb[0] == 1 && lmb[1] == 2 && lmb[2] == 0)
		ra(data);
	else if (lmb[0] == 0 && lmb[1] == 2 && lmb[2] == 1)
	{
		sa(data);
		ra(data);
	}
	else if (lmb[0] == 2 && lmb[1] == 0 && lmb[2] == 1)
		rra(data);
}

void	ps_3(t_data *data, int is_3)
{
	int	*lmb;
	int	i;

	lmb = malloc(3 * sizeof(int));
	assign_lmb(data, lmb);
	cases(data, lmb);
	if (!is_3)
	{
		if (data->len - 4)
		{
			if (data->stk_b->number[0] < data->stk_b->number[1])
				sb(data);
		}
		i = 1;
		while (data->len - 4 + i > 0)
		{
			pa(data);
			i--;
		}
	}
	free(lmb);
	print_last(data);
}

void	ps_5(t_data *data)
{
	int	count;

	count = 0;
	while (count < data->len - 3)
	{
		if (data->stk_a->number[0] <= data->len - 4)
		{
			pb(data);
			count++;
		}
		else
			ra(data);
	}
	ps_3(data, 0);
}
