/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_internal_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 18:47:55 by eallam            #+#    #+#             */
/*   Updated: 2026/11/21 16:33:35 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_INTERNAL_BONUS_H
# define CHECKER_INTERNAL_BONUS_H

# include "stack.h"

int	checker_run(t_stacks *stacks);

int	checker_execute_instruction(t_stacks *stacks, const char *line);

int	checker_execute_push(t_stacks *stacks, const char *line);
int	checker_execute_swap(t_stacks *stacks, const char *line);
int	checker_execute_rotate(t_stacks *stacks, const char *line);
int	checker_execute_reverse_rotate(t_stacks *stacks, const char *line);

#endif /* CHECKER_INTERNAL_BONUS_H */
