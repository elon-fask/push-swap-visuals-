/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by eallam            #+#    #+#             */
/*   Updated: 2026/11/21 16:35:33 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNK_INTERNAL_H
# define CHUNK_INTERNAL_H

# include "chunk.h"
# include <stddef.h>

typedef struct s_chunk_state
{
	t_context	*context;
	size_t		ranks_count;
	size_t		chunk_width;
	size_t		chunk_start_rank;
	size_t		chunk_end_rank;
}				t_chunk_state;

size_t			chunk_group_width(size_t ranks_count);
void			chunk_transfer_groups_to_b(t_chunk_state *state);
void			chunk_restore_to_a(t_context *context);

#endif /* CHUNK_INTERNAL_H */
