/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:20:50 by jvarila           #+#    #+#             */
/*   Updated: 2024/12/19 11:31:27 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static int	validate_input(char **argv);
static int	valid_multinumberstring(char *str);

int	main(int argc, char **argv)
{
	if (argc == 1 || !validate_input(argv + 1))
		return (write_error_return_int("Error", 0));
	return (0);
}

static int	validate_input(char **cl_input)
{
	while (*cl_input != NULL)
	{
		if (ft_strchr(*cl_input, ' '))
		{
			if (!valid_multinumberstring(*cl_input))
				return (0);
		}
		else
		{
			if (!isnumstr(*cl_input)
				|| ft_atol(*cl_input) > INT_MAX
				|| ft_atol(*cl_input) < INT_MIN)
				return (0);
		}
		cl_input++;
	}
	return (1);
}

static int	valid_multinumberstring(char *str)
{
	int	sign;

	if (*str == '\0')
		return (0);
	while (*str)
	{
		sign = 1;
		if (*str == ' ')
		{
			str++;
			continue ;
		}
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
