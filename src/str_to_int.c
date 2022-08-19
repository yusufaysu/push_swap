/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:19:07 by yaysu             #+#    #+#             */
/*   Updated: 2022/06/22 12:56:12 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_data(t_data *data)
{
	char	*s1;
	char	*s2;

	data->stk_a = malloc(sizeof(t_stack));
	data->stk_b = malloc(sizeof(t_stack));
	data->stk_s = malloc(sizeof(t_stack));
	s1 = malloc(sizeof(char) * 5);
	s2 = malloc(sizeof(char) * 5);
	s1[0] = '\0';
	s2[0] = '\0';
	data->o1 = s1;
	data->o2 = s2;
}

int	*nums_str_to_int(char **num, t_data *data)
{
	int	i;
	int	*numbers;

	i = 0;
	while (num[i] != NULL)
		i++;
	numbers = malloc(i * sizeof(int));
	i = 0;
	while (num[i] != NULL)
	{
		numbers[i] = ft_atoi(num[i]);
		i++;
	}
	data->stk_a->len = i;
	data->len = i;
	return (numbers);
}

int	*nums_argv_to_int(int argc, char *argv[], t_data *data)
{
	int	i;
	int	*numbers;

	i = 1;
	numbers = ft_calloc(argc, sizeof(int));
	while (argv[i])
	{
		numbers[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	data->stk_a->len = i - 1;
	data->len = i - 1;
	return (numbers);
}

int	stack_is_sorted(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < data->len)
	{
		if (data->stk_a->number[i - 1] > data->stk_a->number[i])
			j++;
		i++;
	}
	if (j == 0)
		return (0);
	return (1);
}
