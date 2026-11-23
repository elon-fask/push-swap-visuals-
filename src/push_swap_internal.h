/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by eallam            #+#    #+#             */
/*   Updated: 2026/11/21 16:35:07 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_INTERNAL_H
# define PUSH_SWAP_INTERNAL_H

# include "options.h"
# include "stack.h"
# include "stats.h"
# include <stdbool.h>

typedef struct s_context
{
	t_stacks	stacks;
	t_stats		stats;
}				t_context;

double			record_disorder(t_context *context);
void			orchestrator(t_context *context,
					const t_program_options *options);
void			dispatch_strategy(t_context *context,
					const t_program_options *options);

#endif /* PUSH_SWAP_INTERNAL_H */
