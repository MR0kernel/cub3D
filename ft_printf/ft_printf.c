/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:49:28 by guilrodr          #+#    #+#             */
/*   Updated: 2023/12/08 19:41:00 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	read_and_print(char *str, va_list params)
{
	int		index;
	int		return_value;
	int		tmp_value;

	index = 0;
	return_value = 0;
	while (str[index])
	{
		if (str[index] == '%')
			tmp_value = ft_args_control(str[++index], params);
		else
			tmp_value = ft_putchar_fd(str[index], 2);
		if (tmp_value == -1)
		{
			va_end(params);
			return (-1);
		}
		return_value += tmp_value;
		index++;
	}
	return (return_value);
}

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int		return_value;

	if (!str)
		return (-1);
	va_start(params, str);
	return_value = read_and_print((char *)str, params);
	va_end(params);
	return (return_value);
}
