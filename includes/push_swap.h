/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:51:59 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/08 18:13:42 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	char	**args;
	int		a_size;
	int		b_size;
	int		min_elem;
	int		max_elem;
	int		med_elem;
	int		*a;
	int		*b;
	int		*res;
}	t_stack;

typedef struct s_rot_count
{
	int	a_rots;
	int	b_rots;
	int	sum_rots;
}	t_rot_count;

void	push_swap(t_stack *stack, int argc, char **argv);
int		check_if_sorted(int *arr, int size);
void	check_args_unique(int *args_arr, int args_number);
void	check_i_argument(char *arg);
void	zero_stack_struct(t_stack *stack);
void	init_stack_struct(t_stack *stack, int argc, char **argv);
void	quick_sort(int *arr, int start, int end);
void	sort_up_to_six(t_stack *stack);
void	sort_a_up_to_three(t_stack *stack);
void	sort_b_up_to_three(t_stack *stack);
void	sort_many(t_stack *stack);
void	free_stacks(t_stack *stack);
void	find_min_max_elems(t_stack *stack);
void	count_a_rotations(t_stack *stack, t_rot_count *rots, int b_index);
void	count_b_rotations(t_stack *stack, t_rot_count *rots, int b_index);
int		count_final_a_rotations(t_stack *stack);
void	rotate_stack(t_stack *stack, int n, char type);
void	pa(t_stack *stack, int flag);
void	pb(t_stack *stack, int flag);
void	sa(t_stack *stack, int flag);
void	sb(t_stack *stack, int flag);
void	ss(t_stack *stack, int flag);
void	rra(t_stack *stack, int flag);
void	rrb(t_stack *stack, int flag);
void	rrr(t_stack *stack, int flag);
void	ra(t_stack *stack, int flag);
void	rb(t_stack *stack, int flag);
void	rr(t_stack *stack, int flag);
void	checker(t_stack *stack, int argc, char **argv);
int		read_commands(t_stack *stack);

#endif
