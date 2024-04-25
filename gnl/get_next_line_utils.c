/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:31:08 by guilrodr          #+#    #+#             */
/*   Updated: 2023/10/30 21:20:58 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_memmove(char buffer[BUFFER_SIZE + 1], size_t new_line_index)
{
	int		index;
	int		tmp_index;
	int		buffer_index;
	int		buffer_size;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp || !new_line_index)
		return (0);
	buffer_size = ft_strlen(buffer);
	buffer_index = 0;
	tmp_index = 0;
	index = 0;
	while (buffer_size && new_line_index < (size_t) buffer_size)
		tmp[index++] = buffer[new_line_index++];
	tmp[index] = '\0';
	while (tmp[tmp_index])
		buffer[buffer_index++] = tmp[tmp_index++];
	buffer[tmp_index] = '\0';
	free (tmp);
	return (1);
}

int	ft_seek(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str)
		if (str[i++] == '\n')
			return (i);
	return (0);
}

int	ft_fill(char *str, size_t number)
{
	size_t	index;

	index = 0;
	if (!str)
		return (0);
	while (index <= number)
	{
		str[index] = '\0';
		index++;
	}
	return (1);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
