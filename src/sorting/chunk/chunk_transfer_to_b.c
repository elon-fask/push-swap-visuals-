/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_transfer_to_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by eallam            #+#    #+#             */
/*   Updated: 2026/11/21 16:35:42 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk_internal.h"
#include "operations.h"
#include "sorting_utils.h"

static void	set_group_bounds(t_chunk_state *state, size_t chunk_start_rank)
{
	size_t	remaining_ranks;

	state->chunk_start_rank = chunk_start_rank;
	remaining_ranks = state->ranks_count - chunk_start_rank;
	if (state->chunk_width > remaining_ranks)
		state->chunk_end_rank = state->ranks_count;
	else
		state->chunk_end_rank = chunk_start_rank + state->chunk_width;
}

static void	chunk_transfer_group_to_b(t_chunk_state *state)
{
	t_context	*context;
	size_t		remaining;
	size_t		chunk_midpoint;
	int			rank;

	context = state->context;
	remaining = state->chunk_end_rank - state->chunk_start_rank;
	chunk_midpoint = state->chunk_start_rank + remaining / 2;
	while (remaining > 0)
	{
		rank = stack_value_at(&context->stacks.a, 0);
		if ((size_t)rank >= state->chunk_start_rank
			&& (size_t)rank < state->chunk_end_rank)
		{
			operation_pb(&context->stacks, &context->stats);
			if ((size_t)rank < chunk_midpoint)
				operation_rb(&context->stacks.b, &context->stats);
			--remaining;
		}
		else
			operation_ra(&context->stacks.a, &context->stats);
	}
}

void	chunk_transfer_groups_to_b(t_chunk_state *state)
{
	set_group_bounds(state, 0);
	while (state->chunk_start_rank < state->ranks_count)
	{
		chunk_transfer_group_to_b(state);
		set_group_bounds(state, state->chunk_end_rank);
	}
}
