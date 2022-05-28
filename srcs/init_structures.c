/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:52:21 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/08 14:16:24 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	split_one_argument(char *arg, t_stack *stack)
{
	stack->args = ft_split(arg, ' ');
	if (!stack->args)
		ft_print_error("Error");
	stack->a_size = 0;
	while (stack->args[stack->a_size])
		stack->a_size++;
}

static void	define_args_arr(char **args, t_stack *stack, int i_start, int delta)
{
	stack->a = (int *)malloc(sizeof(int) * stack->a_size);
	if (!stack->a)
		ft_print_error("Error");
	while (args[i_start])
	{
		check_i_argument(args[i_start]);
		stack->a[i_start - delta] = ft_atoi(args[i_start]);
		i_start++;
	}
	check_args_unique(stack->a, stack->a_size);
}

void	init_stack_struct(t_stack *stack, int argc, char **argv)
{
	if (argc == 2)
	{
		split_one_argument(argv[1], stack);
		define_args_arr(stack->args, stack, 0, 0);
	}
	else
	{
		stack->a_size = argc - 1;
		define_args_arr(argv, stack, 1, 1);
	}
	stack->b = ft_calloc(stack->a_size, sizeof(int));
	if (!stack->b)
		ft_print_error("Error");
	find_min_max_elems(stack);
}

void	zero_stack_struct(t_stack *stack)
{
	stack->args = NULL;
	stack->a_size = 0;
	stack->b_size = 0;
	stack->a = NULL;
	stack->b = NULL;
	stack->res = NULL;
}
