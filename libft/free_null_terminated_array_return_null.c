/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_null_terminated_array_return_null.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:02:38 by jvarila           #+#    #+#             */
/*   Updated: 2024/12/19 14:11:01 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*free_null_terminated_array_return_null(void ***ptr_to_array)
{
	free_null_terminated_array(ptr_to_array);
	return (NULL);
}
