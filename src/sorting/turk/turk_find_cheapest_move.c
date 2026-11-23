/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_find_cheapest_move.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by eallam            #+#    #+#             */
/*   Updated: 2026/11/21 16:36:07 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting_utils.h"
#include "turk_internal.h"

static void	calculate_rotation_cost(t_turk_move *move)
{
	if (move->source_reverse != move->target_reverse)
		move->total_cost = move->source_rotations + move->target_rotations;
	else if (move->source_rotations > move->target_rotations)
		move->total_cost = move->source_rotations;
	else
		move->total_cost = move->target_rotations;
}

static t_turk_move	create_move_candidate(const t_stack *source,
		const t_stack *destination, size_t source_offset, bool source_is_a)
{
	t_turk_move	candidate;
	int			value;

	value = stack_value_at(source, source_offset);
	candidate = (t_turk_move){0};
	candidate.source_offset = source_offset;
	if (source_is_a)
		stack_find_descending_target(&candidate.target_offset, value,
			destination);
	else
		stack_find_ascending_target(&candidate.target_offset, value,
			destination);
	candidate.source_is_a = source_is_a;
	return (candidate);
}

static void	evaluate_rotation_directions(t_turk_move_search *search,
		const t_turk_move *base, bool source_reverse, bool target_reverse)
{
	t_turk_move	candidate;

	candidate = *base;
	candidate.source_reverse = source_reverse;
	candidate.target_reverse = target_reverse;
	candidate.source_rotations = stack_rotation_distance(search->source_size,
			base->source_offset, source_reverse);
	candidate.target_rotations = stack_rotation_distance(search->target_size,
			base->target_offset, target_reverse);
	calculate_rotation_cost(&candidate);
	if (!search->has_best || candidate.total_cost < search->best.total_cost)
	{
		search->best = candidate;
		search->has_best = true;
	}
}

static void	evaluate_all_directions(t_turk_move_search *search,
		const t_turk_move *candidate)
{
	int	source_direction;
	int	target_direction;

	source_direction = 0;
	while (source_direction < 2)
	{
		target_direction = 0;
		while (target_direction < 2)
		{
			evaluate_rotation_directions(search, candidate,
				source_direction == 1, target_direction == 1);
			++target_direction;
		}
		++source_direction;
	}
}

void	turk_find_cheapest_move(t_turk_move *move, const t_stack *source,
		const t_stack *destination, bool source_is_a)
{
	t_turk_move_search	search;
	t_turk_move			candidate;
	size_t				i;

	search = (t_turk_move_search){0};
	search.source_size = source->size;
	search.target_size = destination->size;
	i = 0;
	while (i < source->size)
	{
		candidate = create_move_candidate(source, destination, i, source_is_a);
		evaluate_all_directions(&search, &candidate);
		++i;
	}
	*move = search.best;
}
