/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operands_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 21:08:18 by eallam            #+#    #+#             */
/*   Updated: 2026/11/13 03:40:55 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDS_INTERNAL_H
# define OPERANDS_INTERNAL_H

# include <stddef.h>
# include "operands.h"

/* Cursor starts at a sign/digit and advances; failure may advance it too. */
int		parse_integer_token(const char **cursor, int *value);
/* Appends to a head-zero stack with enough space; failure may append values. */
int		parse_operand(const char *operand, t_stack *stack);

/* Counts whitespace-delimited tokens without validating their contents. */
size_t	count_operand_tokens(const t_operands *operands);

#endif /* OPERANDS_INTERNAL_H */
