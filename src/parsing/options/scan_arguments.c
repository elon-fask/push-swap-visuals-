/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by eallam            #+#    #+#             */
/*   Updated: 2026/11/21 16:33:18 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "options_internal.h"

static t_argument_kind	classify_argument(const char *argument)
{
	if (argument[0] == '\0')
		return (ARGUMENT_OPERAND);
	if (ft_strcmp(argument, "--") == 0)
		return (ARGUMENT_END_OPTIONS);
	if (argument[0] != '-' || argument[1] == '\0')
		return (ARGUMENT_OPERAND);
	if (argument[1] == '-')
		return (ARGUMENT_LONG_OPTION);
	if (ft_isdigit((unsigned char)argument[1]))
		return (ARGUMENT_OPERAND);
	if (ft_isalpha((unsigned char)argument[1]))
		return (ARGUMENT_SHORT_OPTION);
	return (ARGUMENT_INVALID);
}

static int	store_operand(t_parse_context *context)
{
	t_operands	*operands;

	operands = &context->result->operands;
	operands->arguments[operands->count] = context->argv[context->argi];
	++operands->count;
	++context->argi;
	return (0);
}

static int	process_argument(t_parse_context *context)
{
	t_argument_kind	kind;

	if (!context->options_enabled)
		return (store_operand(context));
	kind = classify_argument(context->argv[context->argi]);
	if (kind == ARGUMENT_END_OPTIONS)
	{
		context->options_enabled = false;
		++context->argi;
		return (0);
	}
	if (kind == ARGUMENT_OPERAND)
		return (store_operand(context));
	if (kind == ARGUMENT_SHORT_OPTION)
		return (parse_short_options(context));
	if (kind == ARGUMENT_LONG_OPTION)
		return (parse_long_option(context));
	return (-1);
}

int	scan_arguments(t_parse_context *context)
{
	context->argi = 1;
	context->options_enabled = true;
	while (context->argi < context->argc)
	{
		if (process_argument(context) != 0)
			return (-1);
	}
	return (0);
}
