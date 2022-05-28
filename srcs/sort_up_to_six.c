/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_up_to_six.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:53:31 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/08 12:57:39 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	come_b_back(t_stack *stack)
{
	int	min;
	int	max_in_stack_a;

	max_in_stack_a = stack->a[stack->a_size - 1];
	min = stack->min_elem;
	while (stack->b_size)
	{
		if (stack->a[0] > stack->b[0] || \
				(stack->a[0] == min && stack->b[0] > max_in_stack_a))
			pa(stack, 1);
		ra(stack, 1);
	}
	while (stack->a[0] != stack->min_elem)
	{
		ra(stack, 1);
	}
}

void	sort_up_to_six(t_stack *stack)
{
	if (stack->a_size == 2)
	{
		sa(stack, 1);
		exit(EXIT_SUCCESS);
	}
	while (stack->a_size > 3)
		pb(stack, 1);
	sort_a_up_to_three(stack);
	if (stack->b_size == 2 && check_if_sorted(stack->b, stack->b_size))
		sb(stack, 1);
	sort_b_up_to_three(stack);
	come_b_back(stack);
}
