/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:22:00 by jvarila           #+#    #+#             */
/*   Updated: 2024/11/27 09:41:37 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

# define CONVERSION_SET "cspdiuxX%"

int	ft_printf(const char *format_str, ...);
int	handle_c(const char **format_str_ptr, va_list ap);
int	handle_s(const char **format_str_ptr, va_list ap);
int	handle_p(const char **format_str_ptr, va_list ap);
int	handle_d(const char **format_str_ptr, va_list ap);
int	handle_i(const char **format_str_ptr, va_list ap);
int	handle_u(const char **format_str_ptr, va_list ap);
int	handle_hex_lowercase(const char **format_str_ptr, va_list ap);
int	handle_hex_uppercase(const char **format_str_ptr, va_list ap);

#endif
