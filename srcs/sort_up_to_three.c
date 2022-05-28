/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_up_to_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:53:36 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/08 13:07:32 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_a_up_to_three(t_stack *stack)
{
	if (!check_if_sorted(stack->a, stack->a_size))
		return ;
	if (stack->a[0] < stack->a[1] && \
			stack->a[0] > stack->a[2] && stack->a[1] > stack->a[2])
		rra(stack, 1);
	else if (stack->a[0] > stack->a[1] && \
			stack->a[0] < stack->a[2] && stack->a[1] < stack->a[2])
		sa(stack, 1);
	else if (stack->a[0] > stack->a[1] && \
			stack->a[0] > stack->a[2] && stack->a[1] < stack->a[2])
		ra(stack, 1);
	else if (stack->a[0] > stack->a[1] && \
			stack->a[0] > stack->a[2] && stack->a[1] > stack->a[2])
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else
	{
		sa(stack, 1);
		ra(stack, 1);
	}
}

void	sort_b_up_to_three(t_stack *stack)
{
	if (!check_if_sorted(stack->b, stack->b_size))
		return ;
	if (stack->b[0] < stack->b[1] && \
			stack->b[0] > stack->b[2] && stack->b[1] > stack->b[2])
		rrb(stack, 1);
	else if (stack->b[0] > stack->b[1] && \
			stack->b[0] < stack->b[2] && stack->b[1] < stack->b[2])
		sb(stack, 1);
	else if (stack->b[0] > stack->b[1] && \
			stack->b[0] > stack->b[2] && stack->b[1] < stack->b[2])
		rb(stack, 1);
	else if (stack->b[0] > stack->b[1] && \
			stack->b[0] > stack->b[2] && stack->b[1] > stack->b[2])
	{
		sb(stack, 1);
		rrb(stack, 1);
	}
	else
	{
		sb(stack, 1);
		rb(stack, 1);
	}
}
