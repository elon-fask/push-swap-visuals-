/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_short_options.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by eallam            #+#    #+#             */
/*   Updated: 2026/11/20 13:48:45 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options_internal.h"

static const t_option_spec	*find_option(const t_option_registry *registry,
		char name)
{
	size_t	i;

	i = 0;
	while (i < registry->count)
	{
		if (registry->specs[i].short_name == name)
			return (&registry->specs[i]);
		++i;
	}
	return (NULL);
}

int	parse_short_options(t_parse_context *context)
{
	const char			*argument;
	const t_option_spec	*option;
	size_t				i;

	argument = context->argv[context->argi];
	i = 1;
	while (argument[i])
	{
		option = find_option(&context->option_registry, argument[i]);
		if (!option || apply_option(context, option) != 0)
			return (-1);
		++i;
	}
	++context->argi;
	return (0);
}
