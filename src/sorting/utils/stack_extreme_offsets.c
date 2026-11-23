/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_extreme_offsets.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by eallam            #+#    #+#             */
/*   Updated: 2026/11/21 16:37:06 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting_utils.h"

static size_t	find_extreme_offset(const t_stack *stack, bool minimum)
{
	size_t	i;
	size_t	best_offset;
	int		best;
	int		current;

	best_offset = 0;
	best = stack_value_at(stack, 0);
	i = 1;
	while (i < stack->size)
	{
		current = stack_value_at(stack, i);
		if ((minimum && current < best) || (!minimum && current > best))
		{
			best = current;
			best_offset = i;
		}
		++i;
	}
	return (best_offset);
}

size_t	stack_minimum_offset(const t_stack *stack)
{
	return (find_extreme_offset(stack, true));
}

size_t	stack_maximum_offset(const t_stack *stack)
{
	return (find_extreme_offset(stack, false));
}
