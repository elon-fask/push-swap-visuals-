/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by eallam            #+#    #+#             */
/*   Updated: 2026/11/17 23:21:25 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options_internal.h"

static int	set_strategy(t_parse_result *result, t_strategy strategy)
{
	if (result->options.strategy_explicit
		&& result->options.strategy != strategy)
		return (-1);
	result->options.strategy = strategy;
	result->options.strategy_explicit = true;
	return (0);
}

int	apply_option(t_parse_context *context, const t_option_spec *option)
{
	if (option->action == OPTION_SET_STRATEGY)
		return (set_strategy(context->result, option->strategy));
	context->result->options.benchmark_enabled = true;
	return (0);
}
