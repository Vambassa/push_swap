/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:53:16 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/08 12:46:36 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(int *stack, int stack_size)
{
	int	tmp;

	if (!stack)
		return ;
	if (stack_size < 2)
		return ;
	tmp = stack[0];
	ft_memmove(stack, stack + 1, sizeof(int) * (stack_size - 1));
	stack[stack_size - 1] = tmp;
}

void	ra(t_stack *stack, int flag)
{
	rotate(stack->a, stack->a_size);
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack, int flag)
{
	rotate(stack->b, stack->b_size);
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack, int flag)
{
	ra(stack, 0);
	rb(stack, 0);
	if (flag == 1)
		write(1, "rr\n", 3);
}
