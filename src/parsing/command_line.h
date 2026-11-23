/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 21:04:07 by eallam            #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_LINE_H
# define COMMAND_LINE_H

# include "options.h"
# include "operands.h"

/* Owns the operand pointer array, but borrows the strings from argv. */
typedef struct s_parse_result
{
	t_program_options	options;
	t_operands			operands;
}						t_parse_result;

/* Separates options from operands; does not validate integer tokens. */
int		parse_command_line(int argc, char **argv, t_parse_result *result);
void	destroy_parse_result(t_parse_result *result);

#endif /* COMMAND_LINE_H */
