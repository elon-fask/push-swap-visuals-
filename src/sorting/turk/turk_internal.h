/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by eallam            #+#    #+#             */
/*   Updated: 2026/11/21 16:36:13 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TURK_INTERNAL_H
# define TURK_INTERNAL_H

# include "turk.h"
# include <stdbool.h>
# include <stddef.h>

typedef struct s_turk_move
{
	size_t		source_offset;
	size_t		target_offset;
	size_t		source_rotations;
	size_t		target_rotations;
	size_t		total_cost;
	bool		source_is_a;
	bool		source_reverse;
	bool		target_reverse;
}				t_turk_move;

typedef struct s_turk_move_search
{
	t_turk_move	best;
	size_t		source_size;
	size_t		target_size;
	bool		has_best;
}				t_turk_move_search;

void			turk_find_cheapest_move(t_turk_move *move,
					const t_stack *source, const t_stack *destination,
					bool source_is_a);

void			turk_execute_move(t_context *context, const t_turk_move *move);
void			turk_rotate_source(t_context *context, const t_turk_move *move);
void			turk_rotate_target(t_context *context, const t_turk_move *move);
void			turk_rotate_both(t_context *context, bool reverse);

#endif /* TURK_INTERNAL_H */
