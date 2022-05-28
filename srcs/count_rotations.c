/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:52:06 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/08 00:52:06 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_final_a_rotations(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack->a[count] != stack->min_elem)
		count++;
	if (count <= stack->a_size - count)
		return (count);
	else
		return (-(stack->a_size - count));
}

void	count_b_rotations(t_stack *stack, t_rot_count *rots, int b_index)
{
	if (b_index <= stack->b_size - b_index)
		rots->b_rots = b_index;
	else
		rots->b_rots = -(stack->b_size - b_index);
}

void	count_a_rotations(t_stack *stack, t_rot_count *rots, int b_index)
{
	int	i;

	if (stack->a[0] > stack->b[b_index] && \
			stack->a[stack->a_size - 1] < stack->b[b_index])
		rots->a_rots = 0;
	i = 0;
	while (i < stack->a_size - 1)
	{
		if (stack->a[i] < stack->b[b_index] && \
				stack->a[i + 1] > stack->b[b_index])
		{
			if (i + 1 <= stack->a_size - i - 1)
				rots->a_rots = i + 1;
			else
				rots->a_rots = -(stack->a_size - i - 1);
		}
		i++;
	}
}
