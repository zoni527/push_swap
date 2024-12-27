/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:07:49 by jvarila           #+#    #+#             */
/*   Updated: 2024/12/27 15:08:02 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_input(char **command_line_input)
{
	while (*command_line_input)
	{
		if (ft_strchr(*command_line_input, ' '))
		{
			if (!valid_multinumberstring(*command_line_input))
				return (0);
		}
		else
		{
			if (!isnumstr(*command_line_input)
				|| ft_atol(*command_line_input) > INT_MAX
				|| ft_atol(*command_line_input) < INT_MIN)
				return (0);
		}
		command_line_input++;
	}
	return (1);
}

int	valid_multinumberstring(char *str)
{
	int	sign;

	if (*str == '\0')
		return (0);
	while (*str)
	{
		sign = 1;
		str = skip_char(str, ' ');
		if ((*str == '-' || *str == '+') && *(str + 1))
			if (*(str++) == '-')
				sign = -1;
		if (!ft_isdigit(*str))
			return (0);
		if ((sign > 0 && ft_atol(str) > INT_MAX)
			|| (sign < 0 && ft_atol(str) > -(long)INT_MIN))
			return (0);
		str++;
	}
	return (1);
}
