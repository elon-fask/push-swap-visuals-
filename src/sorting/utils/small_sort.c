/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by eallam            #+#    #+#             */
/*   Updated: 2026/11/21 16:36:35 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "sorting_utils.h"

static void	sort_two(t_context *context)
{
	int	first;
	int	second;

	first = stack_value_at(&context->stacks.a, 0);
	second = stack_value_at(&context->stacks.a, 1);
	if (first > second)
		operation_sa(&context->stacks.a, &context->stats);
}

void	sort_three(t_context *context)
{
	size_t	maximum_offset;
	t_stack	*stack;

	stack = &context->stacks.a;
	maximum_offset = stack_maximum_offset(stack);
	if (maximum_offset == 0)
		operation_ra(stack, &context->stats);
	else if (maximum_offset == 1)
		operation_rra(stack, &context->stats);
	if (stack_value_at(stack, 0) > stack_value_at(stack, 1))
		operation_sa(stack, &context->stats);
}

static void	move_minimum_to_b(t_context *context)
{
	stack_rotate_minimum_to_top(context, &context->stacks.a);
	operation_pb(&context->stacks, &context->stats);
}

static void	sort_four_or_five(t_context *context)
{
	while (context->stacks.a.size > 3)
		move_minimum_to_b(context);
	sort_three(context);
	while (context->stacks.b.size > 0)
		operation_pa(&context->stacks, &context->stats);
}

void	small_sort(t_context *context)
{
	if (context->stacks.a.size < 2)
		return ;
	if (context->stacks.a.size == 2)
		sort_two(context);
	else if (context->stacks.a.size == 3)
		sort_three(context);
	else
		sort_four_or_five(context);
}
