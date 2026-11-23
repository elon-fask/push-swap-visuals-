/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 21:04:07 by eallam            #+#    #+#             */
/*   Updated: 2026/11/21 16:33:13 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDS_H
# define OPERANDS_H

# include "stack.h"
# include <stddef.h>

typedef struct s_operands
{
	char	**arguments;
	size_t	count;
}			t_operands;

int			parse_operands(const t_operands *operands, t_stacks *stacks);

#endif /* OPERANDS_H */
