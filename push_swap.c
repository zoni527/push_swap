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

static int	validate_input(int argc, char **argv);
static int	validate_multinumberstring(char *str);

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (write_error_return_int("Error", 0));
	if (!validate_input(argc, argv))
		return (write_error_return_int("Error", 0));
	return (0);
}

static int	validate_input(int argc, char **argv)
{
	char	**words;

	if (argc == 2)
		return (validate_multinumberstring(argv[1]));
	words = argv + 1;
	while (*words != NULL)
		if (!isnumstr(*(words++)))
			return (0);
	return (1);
}

static int	validate_multinumberstring(char *str)
{
	char	**words;
	int		i;

	if (*str == '\0')
		return (0);
	words = ft_split(str, ' ');
	if (words == NULL)
		return(
		write_error_return_int("Error: ft_split failed in validate_input", 0));
	i = -1;
	while (words[++i])
		if (!isnumstr(words[i]))
			return (free_null_terminated_array_return_int((void *)&words, 0));
	return (free_null_terminated_array_return_int((void *)&words, 1));
}
