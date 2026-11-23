/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 21:06:13 by eallam            #+#    #+#             */
/*   Updated: 2026/11/21 16:32:38 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operands_internal.h"

int	parse_operands(const t_operands *operands, t_stacks *stacks)
{
	size_t	i;
	size_t	token_count;

	token_count = count_operand_tokens(operands);
	if (token_count == 0 || initialize_stacks(stacks, token_count) != 0)
		return (-1);
	i = 0;
	while (i < operands->count)
	{
		if (parse_operand(operands->arguments[i], &stacks->a) != 0)
		{
			destroy_stacks(stacks);
			return (-1);
		}
		++i;
	}
	return (0);
}
