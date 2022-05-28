/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:51:59 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/08 00:51:59 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_if_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i + 1 < size)
	{
		if (arr[i] > arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	check_args_unique(int *args_arr, int args_number)
{
	int	i;
	int	j;

	i = 0;
	while (i < args_number)
	{
		j = i + 1;
		while (j < args_number)
		{
			if (args_arr[i] == args_arr[j])
				ft_print_error("Error");
			j++;
		}
		i++;
	}
}

static void	check_overflow(char *arg)
{
	char	*cmp;
	int		arg_len;
	int		cmp_len;

	if (arg[0] == '-')
		cmp = ft_itoa(INT_MIN);
	else
		cmp = ft_itoa(INT_MAX);
	arg_len = ft_strlen(arg);
	cmp_len = ft_strlen(cmp);
	if (arg_len > cmp_len)
		ft_print_error("Error");
	else if (arg_len == cmp_len && ft_strcmp(arg, cmp) > 0)
		ft_print_error("Error");
	free(cmp);
}

static void	check_digits(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' && ft_isdigit(arg[i + 1]))
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			ft_print_error("Error");
		i++;
	}
}

void	check_i_argument(char *arg)
{
	check_digits(arg);
	check_overflow(arg);
}
