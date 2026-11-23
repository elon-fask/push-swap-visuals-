/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_execute_push_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:57:57 by eallam            #+#    #+#             */
/*   Updated: 2026/11/21 16:33:25 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_internal_bonus.h"
#include "libft.h"

static void	transfer_top(t_stack *source, t_stack *destination)
{
	int	value;

	if (stack_pop_top(source, &value) == STACK_UNCHANGED)
		return ;
	stack_push_top(destination, value);
}

int	checker_execute_push(t_stacks *stacks, const char *line)
{
	if (ft_strcmp(line, "pa") == 0)
		transfer_top(&stacks->b, &stacks->a);
	else if (ft_strcmp(line, "pb") == 0)
		transfer_top(&stacks->a, &stacks->b);
	else
		return (-1);
	return (0);
}
