/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:49:28 by guilrodr          #+#    #+#             */
/*   Updated: 2023/12/08 19:42:49 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent_handler(char c)
{
	if (c)
	{
		ft_putchar_fd('%', 1);
		if (c != '\0')
		{
			ft_putchar_fd(c, 1);
			return (2);
		}
	}
	return (-1);
}

int	ft_args_control(char c, va_list params)
{
	int	value;

	value = 0;
	if (c == 'c')
		value = ft_putchar_fd(va_arg(params, int), 2);
	else if (c == 's')
		value = ft_get_string(params);
	else if (c == 'u')
		value = ft_get_unsigned_int(params);
	else if (c == 'd' || c == 'i')
		value = ft_get_int(params);
	else if (c == 'x')
		value = ft_get_base(params, "0123456789abcdef");
	else if (c == 'X')
		value = ft_get_base(params, "0123456789ABCDEF");
	else if (c == 'p')
		value = ft_get_address(params, "0123456789abcdef");
	else if (c == '%')
		value = ft_putchar_fd('%', 2);
	else
		value = ft_percent_handler(c);
	return (value);
}
