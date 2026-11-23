/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by eallam            #+#    #+#             */
/*   Updated: 2026/11/21 16:36:27 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting_utils.h"
#include "turk_internal.h"

void	turk_sort(t_context *context)
{
	t_turk_move	move;

	if (context->stacks.a.size <= 5)
	{
		small_sort(context);
		return ;
	}
	while (context->stacks.a.size > 3)
	{
		turk_find_cheapest_move(&move, &context->stacks.a, &context->stacks.b,
			true);
		turk_execute_move(context, &move);
	}
	sort_three(context);
	while (context->stacks.b.size > 0)
	{
		turk_find_cheapest_move(&move, &context->stacks.b, &context->stacks.a,
			false);
		turk_execute_move(context, &move);
	}
	stack_rotate_minimum_to_top(context, &context->stacks.a);
}
