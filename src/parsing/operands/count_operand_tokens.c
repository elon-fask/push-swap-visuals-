/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_operand_tokens.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 21:03:01 by eallam            #+#    #+#             */
/*   Updated: 2026/11/12 21:18:48 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "operands_internal.h"

static size_t	count_tokens_in_operand(const char *operand)
{
	size_t	count;

	count = 0;
	while (*operand)
	{
		while (*operand && ft_isspace(*operand))
			++operand;
		if (*operand)
		{
			++count;
			while (*operand && !ft_isspace(*operand))
				++operand;
		}
	}
	return (count);
}

size_t	count_operand_tokens(const t_operands *operands)
{
	size_t	i;
	size_t	token_count;

	i = 0;
	token_count = 0;
	while (i < operands->count)
	{
		token_count += count_tokens_in_operand(operands->arguments[i]);
		++i;
	}
	return (token_count);
}
