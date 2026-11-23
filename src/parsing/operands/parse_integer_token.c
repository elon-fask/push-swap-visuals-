/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_integer_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eallam <eallam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 16:31:44 by eallam            #+#    #+#             */
/*   Updated: 2026/11/21 16:31:56 by eallam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	parse_sign(const char **cursor)
{
	int	sign;

	sign = 1;
	if (**cursor == '+' || **cursor == '-')
	{
		if (**cursor == '-')
			sign = -1;
		++(*cursor);
	}
	return (sign);
}

static int	parse_magnitude(const char **cursor, unsigned int limit,
		unsigned int *magnitude)
{
	unsigned int	digit;

	*magnitude = 0;
	while (ft_isdigit((unsigned char)**cursor))
	{
		digit = (unsigned int)(**cursor - '0');
		if (*magnitude > (limit - digit) / 10U)
			return (-1);
		*magnitude = *magnitude * 10U + digit;
		++(*cursor);
	}
	return (0);
}

int	parse_integer_token(const char **cursor, int *value)
{
	unsigned int	magnitude;
	unsigned int	limit;
	int				sign;

	sign = parse_sign(cursor);
	if (!ft_isdigit((unsigned char)**cursor))
		return (-1);
	limit = (unsigned int)INT_MAX;
	if (sign < 0)
		limit = (unsigned int)(-(INT_MIN + 1)) + 1U;
	if (parse_magnitude(cursor, limit, &magnitude) != 0)
		return (-1);
	if (**cursor && !ft_isspace((unsigned char)**cursor))
		return (-1);
	if (sign < 0 && magnitude == limit)
		*value = INT_MIN;
	else if (sign < 0)
		*value = -(int)magnitude;
	else
		*value = (int)magnitude;
	return (0);
}
