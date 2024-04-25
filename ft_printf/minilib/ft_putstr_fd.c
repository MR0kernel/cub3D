/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:49:28 by guilrodr          #+#    #+#             */
/*   Updated: 2023/12/08 19:51:38 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	index;

	fd = 2;
	if (!s)
		return (0);
	index = 0;
	while (s[index] && s[index] != '\0')
	{
		ft_putchar_fd(s[index], fd);
		index++;
	}
	return (index);
}
