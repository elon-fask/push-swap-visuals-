/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by eallam            #+#    #+#             */
/*   Updated: 2026/11/21 16:37:15 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "sorting_utils.h"

size_t	stack_rotation_distance(size_t size, size_t offset, bool reverse)
{
	if (offset == 0)
		return (0);
	if (reverse)
		return (size - offset);
	return (offset);
}

static void	rotate_once(t_context *context, t_stack *stack, bool reverse)
{
	if (stack == &context->stacks.a)
	{
		if (reverse)
			operation_rra(stack, &context->stats);
		else
			operation_ra(stack, &context->stats);
	}
	else if (reverse)
		operation_rrb(stack, &context->stats);
	else
		operation_rb(stack, &context->stats);
}

static void	rotate_steps(t_context *context, t_stack *stack, size_t steps,
		bool reverse)
{
	while (steps > 0)
	{
		rotate_once(context, stack, reverse);
		--steps;
	}
}

void	stack_rotate_to_offset(t_context *context, t_stack *stack,
		size_t target_offset)
{
	size_t	forward_steps;
	size_t	reverse_steps;

	forward_steps = stack_rotation_distance(stack->size, target_offset, false);
	reverse_steps = stack_rotation_distance(stack->size, target_offset, true);
	if (forward_steps < reverse_steps)
		rotate_steps(context, stack, forward_steps, false);
	else
		rotate_steps(context, stack, reverse_steps, true);
}

void	stack_rotate_minimum_to_top(t_context *context, t_stack *stack)
{
	size_t	offset;

	offset = stack_minimum_offset(stack);
	stack_rotate_to_offset(context, stack, offset);
}
