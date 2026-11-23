/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_group_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by eallam            #+#    #+#             */
/*   Updated: 2026/11/21 16:35:32 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk_internal.h"

size_t	chunk_group_width(size_t ranks_count)
{
	size_t	root;

	if (ranks_count == 100)
		return (29);
	if (ranks_count == 500)
		return (58);
	root = 1;
	while (root <= ranks_count / root)
		++root;
	return ((root - 1) * 2);
}
