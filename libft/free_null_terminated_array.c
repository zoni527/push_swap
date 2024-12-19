/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_null_terminated_array.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:02:38 by jvarila           #+#    #+#             */
/*   Updated: 2024/12/19 14:58:49 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_null_terminated_array(void ***ptr_to_array)
{
	void	**null_terminated_array;

	null_terminated_array = *ptr_to_array;
	while (*null_terminated_array != NULL)
		free(*(null_terminated_array++));
	free(*(null_terminated_array));
	free(*ptr_to_array);
	*ptr_to_array = NULL;
}
