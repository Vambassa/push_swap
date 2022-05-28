/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:52:43 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/08 18:07:14 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(int *stack, int stack_size)
{
	int	tmp;

	if (!stack)
		return ;
	if (stack_size < 2)
		return ;
	tmp = stack[stack_size - 1];
	ft_memmove(stack + 1, stack, sizeof(int) * (stack_size - 1));
	stack[0] = tmp;
}

void	rra(t_stack *stack, int flag)
{
	reverse_rotate(stack->a, stack->a_size);
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack, int flag)
{
	reverse_rotate(stack->b, stack->b_size);
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack, int flag)
{
	rra(stack, 0);
	rrb(stack, 0);
	if (flag == 1)
		write(1, "rrr\n", 4);
}
