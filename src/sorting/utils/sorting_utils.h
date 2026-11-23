/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by eallam            #+#    #+#             */
/*   Updated: 2026/11/21 16:37:01 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_UTILS_H
# define SORTING_UTILS_H

# include "push_swap_internal.h"
# include <stdbool.h>
# include <stddef.h>

int		stack_rank_values(t_stack *stack);

size_t	stack_physical_index(const t_stack *stack, size_t offset);
int		stack_value_at(const t_stack *stack, size_t offset);
size_t	stack_minimum_offset(const t_stack *stack);
size_t	stack_maximum_offset(const t_stack *stack);
size_t	stack_rotation_distance(size_t size, size_t offset, bool reverse);

void	stack_rotate_to_offset(t_context *context, t_stack *stack,
			size_t target_offset);

void	small_sort(t_context *context);
void	sort_three(t_context *context);
void	stack_rotate_minimum_to_top(t_context *context, t_stack *stack);
void	stack_find_ascending_target(size_t *target, int value,
			const t_stack *stack);
void	stack_find_descending_target(size_t *target, int value,
			const t_stack *stack);

#endif /* SORTING_UTILS_H */
