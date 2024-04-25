/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:49:28 by guilrodr          #+#    #+#             */
/*   Updated: 2023/12/08 19:43:48 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_int(va_list param)
{
	int	value;

	value = va_arg(param, int);
	return (ft_putnbr_fd(value, 2));
}

int	ft_get_unsigned_int(va_list param)
{
	unsigned int	value;
	int				return_value;

	value = va_arg(param, unsigned int);
	return_value = 0;
	return_value += ft_put_unsigned_nbr_fd(value, 2);
	return (return_value);
}

int	ft_get_address(va_list param, char *base_array)
{
	size_t		number;
	int			value;

	number = va_arg(param, size_t);
	value = 0;
	if (number == 0)
		return (ft_putstr_fd("(nil)", 2));
	value += ft_putstr_fd("0x", 2);
	value += ft_base(number, 16, base_array, 0);
	return (value);
}

int	ft_get_base(va_list param, char *base)
{
	unsigned int	number;

	number = va_arg(param, unsigned int);
	return (ft_base(number, 16, base, 0));
}

int	ft_get_string(va_list param)
{
	char	*string;

	string = va_arg(param, char *);
	if (string == NULL)
		return (ft_putstr_fd("(null)", 2));
	return (ft_putstr_fd(string, 2));
}
