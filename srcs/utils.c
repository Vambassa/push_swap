/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:53:44 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/08 12:29:04 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stacks(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack->res)
		free(stack->res);
	if (stack->args)
	{
		while (stack->args[i])
		{
			free(stack->args[i]);
			i++;
		}
	}
	free(stack->args);
}

void	find_min_max_elems(t_stack *stack)
{
	stack->res = ft_calloc(stack->a_size, sizeof(int));
	if (!stack->res)
		ft_print_error("Error");
	ft_memcpy(stack->res, stack->a, stack->a_size * sizeof(int));
	quick_sort(stack->res, 0, stack->a_size - 1);
	stack->min_elem = stack->res[0];
	stack->med_elem = stack->res[stack->a_size / 2];
	stack->max_elem = stack->res[stack->a_size - 1];
}
