/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_long_option.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by eallam            #+#    #+#             */
/*   Updated: 2026/11/20 13:47:53 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "options_internal.h"

static const t_option_spec	*find_long_option(const t_option_registry *registry,
		const char *name)
{
	size_t	i;

	i = 0;
	while (i < registry->count)
	{
		if (ft_strcmp(registry->specs[i].long_name, name) == 0)
			return (&registry->specs[i]);
		++i;
	}
	return (NULL);
}

int	parse_long_option(t_parse_context *context)
{
	const char			*name;
	const t_option_spec	*option;

	name = context->argv[context->argi] + 2;
	option = find_long_option(&context->option_registry, name);
	if (!option || apply_option(context, option) != 0)
		return (-1);
	++context->argi;
	return (0);
}
