/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:52:36 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/08 18:08:19 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack *stack, int flag)
{
	if (stack->b_size > 0)
	{
		ft_memmove(stack->a + 1, stack->a, sizeof(int) * stack->a_size);
		stack->a[0] = stack->b[0];
		stack->a_size++;
		stack->b_size--;
		ft_memmove(stack->b, stack->b + 1, sizeof(int) * stack->b_size);
		stack->b[stack->b_size] = 0;
		if (flag == 1)
			write(1, "pa\n", 3);
	}
}

void	pb(t_stack *stack, int flag)
{
	if (stack->a_size > 0)
	{
		ft_memmove(stack->b + 1, stack->b, sizeof(int) * stack->b_size);
		stack->b[0] = stack->a[0];
		stack->b_size++;
		stack->a_size--;
		ft_memmove(stack->a, stack->a + 1, sizeof(int) * stack->a_size);
		stack->a[stack->a_size] = 0;
		if (flag == 1)
			write(1, "pb\n", 3);
	}
}
