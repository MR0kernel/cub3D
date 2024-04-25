/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:31:23 by guilrodr          #+#    #+#             */
/*   Updated: 2023/10/30 21:34:57 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		reader;
	char		*line;
	int			buffer_index;
	int			malloc_err_control;

	line = NULL;
	malloc_err_control = 0;
	reader = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) == -1)
		return (NULL);
	while (reader > 0 && malloc_err_control != -1)
	{
		malloc_err_control = new_line(buffer, &line);
		if (malloc_err_control == 1)
			break ;
		buffer_index = ft_strlen(buffer);
		if (buffer_index)
			line = ft_join_line(buffer, line, buffer_index);
		ft_fill(buffer, BUFFER_SIZE + 1);
		reader = read(fd, buffer, BUFFER_SIZE);
	}
	if ((reader == -1) || (malloc_err_control == -1))
		return (error_that_will_never_happen(buffer, line), NULL);
	return (line);
}

void	error_that_will_never_happen(char buffer[BUFFER_SIZE + 1], char *line)
{
	ft_fill(buffer, BUFFER_SIZE + 1);
	if (line)
		free(line);
}

char	*ft_join_line(char buffer[BUFFER_SIZE + 1], char *line, int new)
{
	char	*new_line;
	size_t	malloc_size;
	int		copy_index;
	int		buffer_index;

	copy_index = 0;
	buffer_index = 0;
	malloc_size = ft_strlen(line);
	new_line = (char *)malloc(sizeof(char) * (malloc_size + new + 1));
	if (!new_line)
		return (NULL);
	while (line && line[copy_index])
	{
		new_line[copy_index] = line[copy_index];
		copy_index ++;
	}
	while (buffer_index < new)
		new_line[copy_index++] = buffer[buffer_index++];
	new_line[copy_index] = '\0';
	if (line)
		free(line);
	return (new_line);
}

int	new_line(char buffer[BUFFER_SIZE + 1], char **line)
{
	int	new_line_index;

	new_line_index = ft_seek(buffer);
	if (new_line_index)
	{
		*line = ft_join_line(buffer, *line, new_line_index);
		if (!*line)
			return (-1);
		if (!ft_memmove(buffer, new_line_index))
			return (-1);
		return (1);
	}
	return (0);
}
