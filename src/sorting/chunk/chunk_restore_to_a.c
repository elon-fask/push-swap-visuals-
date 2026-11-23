/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_restore_to_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by eallam            #+#    #+#             */
/*   Updated: 2026/11/21 16:35:35 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk_internal.h"
#include "operations.h"
#include "sorting_utils.h"

void	chunk_restore_to_a(t_context *context)
{
	size_t	maximum_offset;

	while (context->stacks.b.size > 0)
	{
		maximum_offset = stack_maximum_offset(&context->stacks.b);
		stack_rotate_to_offset(context, &context->stacks.b, maximum_offset);
		operation_pa(&context->stacks, &context->stats);
	}
}
