/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:53:40 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/08 12:43:05 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(int *stack, int stack_size)
{
	int		tmp;

	if (!stack)
		return ;
	if (stack_size < 2)
		return ;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void	sa(t_stack *stack, int flag)
{
	swap(stack->a, stack->a_size);
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack, int flag)
{
	swap(stack->b, stack->b_size);
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stack, int flag)
{
	sa(stack, 0);
	sb(stack, 0);
	if (flag == 1)
		write(1, "ss\n", 3);
}
