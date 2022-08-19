/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaysu <yaysu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:53:49 by yaysu             #+#    #+#             */
/*   Updated: 2022/06/14 18:34:24 by yaysu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	operation_checker_tml(t_data	*data, char	*str1, char	*str2)
{
	ft_putstr_fd(str1, 1);
	ft_strlcpy(data->o1, str2, ft_strlen(str2) + 1);
	data->o2[0] = '\0';
	return (1);
}

int	operation_checker(t_data *data, char	*str)
{
	if ((ft_strncmp(data->o1, "sa\n", 5) == 0
			&& ft_strncmp(data->o2, "sb\n", 5) == 0)
		|| (ft_strncmp(data->o1, "sb\n", 5) == 0
			&& ft_strncmp(data->o2, "sa\n", 5) == 0))
		return (operation_checker_tml(data, "ss\n", str));
	else if ((ft_strncmp(data->o1, "ra\n", 5) == 0
			&& ft_strncmp(data->o2, "rb\n", 5) == 0)
		|| (ft_strncmp(data->o1, "rb\n", 5) == 0
			&& ft_strncmp(data->o2, "ra\n", 5) == 0))
		return (operation_checker_tml(data, "rr\n", str));
	else if ((ft_strncmp(data->o1, "rra\n", 5) == 0
			&& ft_strncmp(data->o2, "rrb\n", 5) == 0)
		|| (ft_strncmp(data->o1, "rrb\n", 5) == 0
			&& ft_strncmp(data->o2, "rra\n", 5) == 0))
		return (operation_checker_tml(data, "rrr\n", str));
	return (0);
}

void	print_operation(t_data	*data, char	*str)
{
	int	operation_check;

	if (data->o1[0] == '\0')
		ft_strlcpy(data->o1, str, ft_strlen(str) + 1);
	else if (data->o2[0] == '\0')
		ft_strlcpy(data->o2, str, ft_strlen(str) + 1);
	else
	{
		operation_check = operation_checker(data, str);
		if (!operation_check)
		{
			ft_putstr_fd(data->o1, 1);
			ft_strlcpy(data->o1, data->o2, ft_strlen(data->o2) + 1);
			ft_strlcpy(data->o2, str, ft_strlen(str) + 1);
		}
	}
}

void	print_last(t_data *data)
{
	if (data->o1[0] != '\0')
		ft_putstr_fd(data->o1, 1);
	if (data->o2[0] != '\0')
		ft_putstr_fd(data->o2, 1);
}
