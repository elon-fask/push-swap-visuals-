/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by eallam            #+#    #+#             */
/*   Updated: 2026/11/21 16:35:36 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk_internal.h"
#include "sorting_utils.h"
#include "turk.h"

void	chunk_sort(t_context *context)
{
	t_chunk_state	state;

	if (context->stacks.a.size <= 5)
	{
		small_sort(context);
		return ;
	}
	state = (t_chunk_state){0};
	state.context = context;
	state.ranks_count = context->stacks.a.size;
	if (stack_rank_values(&context->stacks.a) == -1)
	{
		stats_set_selected_strategy(&context->stats, STRATEGY_COMPLEX);
		turk_sort(context);
		return ;
	}
	state.chunk_width = chunk_group_width(state.ranks_count);
	chunk_transfer_groups_to_b(&state);
	chunk_restore_to_a(context);
}
