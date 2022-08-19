/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:53:49 by yaysu             #+#    #+#             */
/*   Updated: 2022/06/22 12:47:05 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_numbers(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && !(j == 0 && argv[i][j]
				== '-' && ft_isdigit(argv[i][j + 1])))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_if_int(char **argv)
{
	int		i;
	long	max_int;
	long	min_int;

	i = 0;
	max_int = 2147483647;
	min_int = -2147483468;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 11)
			return (-1);
		if (ft_atoll(argv[i]) > max_int || ft_atoll(argv[i]) < min_int)
			return (-1);
		i++;
	}
	return (0);
}

int	check_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (!ft_strncmp(argv[i], argv[j], 12))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_input(char **argv)
{
	argv++;
	if (check_numbers(argv) == -1)
		return (-1);
	if (check_if_int(argv) == -1)
		return (-1);
	if (check_duplicates(argv) == -1)
		return (-1);
	return (0);
}

void	before_start(int argc, char **argv, t_data *data)
{
	char	***arr;
	char	**num;

	arr = &argv;
	check_data(argc, argv);
	init_data(data);
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		num = ft_split(argv[1], ' ');
		data->stk_a->number = nums_str_to_int(num, data);
		arr = &num;
	}
	else
		data->stk_a->number = nums_argv_to_int(argc, argv, data);
	data->stk_b->number = malloc(data->stk_a->len * sizeof(int));
	data->stk_b->len = 0;
	if (check_input(*arr) == -1)
	{
		if (argc == 2 && ft_strchr(argv[1], ' '))
			free_array(num);
		free_everything(data);
		print_error("Error\n");
	}
	if (argc == 2 && ft_strchr(argv[1], ' '))
		free_array(num);
}
