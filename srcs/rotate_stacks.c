/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:53:22 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/08 12:56:09 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	define_rotation(t_stack *stack, int sign, char type)
{
	if (sign == 1)
	{
		if (type == 'a')
			ra(stack, 1);
		else
			rb(stack, 1);
	}
	else
	{
		if (type == 'a')
			rra(stack, 1);
		else
			rrb(stack, 1);
	}
}

void	rotate_stack(t_stack *stack, int n, char type)
{
	int	sign;

	if (n > 0)
		sign = 1;
	else
	{
		sign = -1;
		n = -n;
	}
	while (n > 0)
	{
		define_rotation(stack, sign, type);
		n--;
	}
}
