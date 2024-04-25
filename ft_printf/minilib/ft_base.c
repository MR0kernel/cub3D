/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:49:28 by guilrodr          #+#    #+#             */
/*   Updated: 2023/10/14 20:49:43 by guilrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_base(unsigned long number, int base_number, char base_array[], int value)
{
	char	character;

	value = 0;
	if (number >= (unsigned long)base_number)
	{
		value += ft_base(number / base_number, base_number, base_array, value);
		value += ft_base(number % base_number, base_number, base_array, value);
	}
	else
	{
		character = base_array[number];
		value += ft_putchar_fd(character, 1);
		return (value);
	}
	return (value);
}
