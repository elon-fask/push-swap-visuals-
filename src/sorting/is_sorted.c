/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 22:23:58 by eallam            #+#    #+#             */
/*   Updated: 2026/11/21 16:37:35 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_sorted.h"
#include "sorting_utils.h"

bool	is_sorted(const t_stack *stack)
{
	size_t	i;
	int		current;
	int		next;

	i = 0;
	while (i + 1 < stack->size)
	{
		current = stack_value_at(stack, i);
		next = stack_value_at(stack, i + 1);
		if (current > next)
			return (false);
		++i;
	}
	return (true);
}
