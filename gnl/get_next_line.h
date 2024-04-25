/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:31:31 by guilrodr          #+#    #+#             */
/*   Updated: 2023/10/30 21:26:45 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char *str);
int		ft_fill(char *str, size_t number);
int		ft_seek(char *str);
int		ft_memmove(char buffer[BUFFER_SIZE + 1], size_t new_line_index);
char	*get_next_line(int fd);
char	*ft_join_line(char buffer[BUFFER_SIZE + 1], char *line, int new);
int		new_line(char buffer[BUFFER_SIZE + 1], char **line);
void	error_that_will_never_happen(char buffer[BUFFER_SIZE + 1], char *line);

#endif
