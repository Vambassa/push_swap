/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:52:15 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/08 18:08:40 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	handle_commands(t_stack *stack, char *cmd)
{
	if (!ft_strcmp(cmd, "sa\n"))
		sa(stack, 0);
	else if (!ft_strcmp(cmd, "sb\n"))
		sb(stack, 0);
	else if (!ft_strcmp(cmd, "ss\n"))
		ss(stack, 0);
	else if (!ft_strcmp(cmd, "pa\n"))
		pa(stack, 0);
	else if (!ft_strcmp(cmd, "pb\n"))
		pb(stack, 0);
	else if (!ft_strcmp(cmd, "ra\n"))
		ra(stack, 0);
	else if (!ft_strcmp(cmd, "rb\n"))
		rb(stack, 0);
	else if (!ft_strcmp(cmd, "rr\n"))
		rr(stack, 0);
	else if (!ft_strcmp(cmd, "rra\n"))
		rra(stack, 0);
	else if (!ft_strcmp(cmd, "rrb\n"))
		rrb(stack, 0);
	else if (!ft_strcmp(cmd, "rrr\n"))
		rrr(stack, 0);
	else
		return (-1);
	return (0);
}

int	read_commands(t_stack *stack)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		if (handle_commands(stack, cmd))
		{
			ft_putendl_fd("Error", 2);
			return (-1);
		}
		free(cmd);
		cmd = get_next_line(0);
	}
	free(cmd);
	return (0);
}
