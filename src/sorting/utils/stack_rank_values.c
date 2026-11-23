/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rank_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:00:00 by eallam            #+#    #+#             */
/*   Updated: 2026/11/21 16:37:11 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting_utils.h"
#include <stdlib.h>

static size_t	count_smaller_values(const int *values, size_t size, int value)
{
	size_t	i;
	size_t	rank;

	i = 0;
	rank = 0;
	while (i < size)
	{
		if (values[i] < value)
			++rank;
		++i;
	}
	return (rank);
}

int	stack_rank_values(t_stack *stack)
{
	int		*original_values;
	size_t	i;
	size_t	rank;

	if (stack->size == 0)
		return (0);
	original_values = malloc(stack->size * sizeof(*original_values));
	if (original_values == NULL)
		return (-1);
	i = 0;
	while (i < stack->size)
	{
		original_values[i] = stack_value_at(stack, i);
		++i;
	}
	i = 0;
	while (i < stack->size)
	{
		rank = count_smaller_values(original_values, stack->size,
				original_values[i]);
		stack->data[stack_physical_index(stack, i)] = (int)rank;
		++i;
	}
	free(original_values);
	return (0);
}
