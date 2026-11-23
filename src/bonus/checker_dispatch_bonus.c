/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_dispatch_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:57:52 by eallam            #+#    #+#             */
/*   Updated: 2026/11/21 16:33:24 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_internal_bonus.h"

int	checker_execute_instruction(t_stacks *stacks, const char *line)
{
	if (line[0] == 's')
		return (checker_execute_swap(stacks, line));
	if (line[0] == 'p')
		return (checker_execute_push(stacks, line));
	if (line[0] == 'r' && line[1] == 'r' && line[2] != '\0')
		return (checker_execute_reverse_rotate(stacks, line));
	if (line[0] == 'r')
		return (checker_execute_rotate(stacks, line));
	return (-1);
}
