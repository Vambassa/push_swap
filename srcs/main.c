/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:52:26 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/08 00:52:26 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_stack *stack, int argc, char **argv)
{
	zero_stack_struct(stack);
	init_stack_struct(stack, argc, argv);
	if (!check_if_sorted(stack->a, stack->a_size))
		exit(EXIT_SUCCESS);
	else if (stack->a_size <= 6)
		sort_up_to_six(stack);
	else
		sort_many(stack);
	free_stacks(stack);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 1)
		return (0);
	push_swap(&stack, argc, argv);
	return (0);
}
