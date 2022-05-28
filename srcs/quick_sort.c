/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:52:40 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/08 12:36:46 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *arr, int start, int end)
{
	int	i;
	int	j;
	int	pivot;

	pivot = arr[end];
	i = start - 1;
	j = start;
	while (j <= end - 1)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[end]);
	return (i + 1);
}

void	quick_sort(int *arr, int start, int end)
{
	int	pivot_index;

	if (start < end)
	{
		pivot_index = partition(arr, start, end);
		quick_sort(arr, start, pivot_index - 1);
		quick_sort(arr, pivot_index + 1, end);
	}
}
