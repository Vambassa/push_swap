/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:53:27 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/08 12:31:50 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	count_element_rots(t_stack *stack, t_rot_count *rots, int b_index)
{
	count_a_rotations(stack, rots, b_index);
	count_b_rotations(stack, rots, b_index);
	rots->sum_rots = ft_abs(rots->a_rots) + ft_abs(rots->b_rots);
}

static	void	find_next_rot(t_stack *stack, t_rot_count *rots)
{
	int			b_index;
	t_rot_count	other_rots;

	count_element_rots(stack, rots, 0);
	b_index = 1;
	while (b_index < stack->b_size)
	{
		count_element_rots(stack, &other_rots, b_index);
		if (other_rots.sum_rots < rots->sum_rots)
		{
			rots->a_rots = other_rots.a_rots;
			rots->b_rots = other_rots.b_rots;
			rots->sum_rots = other_rots.sum_rots;
		}
		b_index++;
	}
}

void	sort_many(t_stack *stack)
{
	t_rot_count	rots;
	int			final_rot_a;

	while (stack->a_size > 2)
	{
		if (stack->a[0] != stack->min_elem && stack->a[0] != stack->max_elem)
		{
			pb(stack, 1);
			if (stack->b[0] > stack->med_elem)
				rb(stack, 1);
		}
		else
			ra(stack, 1);
	}
	while (stack->b_size)
	{
		find_next_rot(stack, &rots);
		rotate_stack(stack, rots.a_rots, 'a');
		rotate_stack(stack, rots.b_rots, 'b');
		pa(stack, 1);
	}
	final_rot_a = count_final_a_rotations(stack);
	rotate_stack(stack, final_rot_a, 'a');
}
