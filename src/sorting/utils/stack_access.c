/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by eallam            #+#    #+#             */
/*   Updated: 2026/11/21 16:37:03 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting_utils.h"

size_t	stack_physical_index(const t_stack *stack, size_t offset)
{
	return ((stack->head + offset) % stack->capacity);
}

int	stack_value_at(const t_stack *stack, size_t offset)
{
	return (stack->data[stack_physical_index(stack, offset)]);
}
