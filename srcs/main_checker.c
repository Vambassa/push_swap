/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:52:31 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/08 18:07:42 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	checker(t_stack *stack, int argc, char **argv)
{
	zero_stack_struct(stack);
	init_stack_struct(stack, argc, argv);
	if (read_commands(stack) != -1)
	{
		if (!check_if_sorted(stack->a, stack->a_size) && !stack->b_size)
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
	}
	free_stacks(stack);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 1)
		return (0);
	checker(&stack, argc, argv);
	return (0);
}
