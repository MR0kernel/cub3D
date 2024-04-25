/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:28:51 by guilrodr          #+#    #+#             */
/*   Updated: 2023/12/10 13:52:32 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_map_size(t_master *master);
void	place_values(t_master *master, int y_index, int x_index);
void	stock_map(t_master *master);

void	map_stock_master(t_master *master)
{
	init_map_size(master);
	stock_map(master);
}

void	init_map_size(t_master *master)
{
	int		fd;
	char	*map_line;
	size_t	y_index;
	size_t	x_index;

	y_index = 0;
	x_index = 0;
	fd = open(master->given_map, O_RDONLY);
	map_line = get_next_line(fd);
	if (map_line == NULL)
		basic_error_handler(master, 4);
	x_index = str_len(map_line);
	while (map_line || x_index == 0)
	{
		y_index++;
		if (x_index == 0 || str_len(map_line) != x_index)
		{
			free(map_line);
			basic_error_handler(master, 5);
		}
		free(map_line);
		map_line = get_next_line(fd);
	}
	close(fd);
	place_values(master, y_index, x_index);
}

void	place_values(t_master *master, int y_index, int x_index)
{
	master->map.map_size_y = y_index;
	master->map.map_size_x = x_index - 1;
	master->map.original_map = malloc(sizeof(char *) * y_index + 1);
	if (!master->map.original_map)
		basic_error_handler(master, 6);
}

void	stock_map(t_master *master)
{
	int		fd;
	char	*map_line;
	size_t	index;

	index = 0;
	fd = open(master->given_map, O_RDONLY);
	map_line = get_next_line(fd);
	if (!map_line)
		basic_error_handler(master, 6);
	while (map_line)
	{
		master->map.original_map[index] = map_line;
		map_line = get_next_line(fd);
		index++;
	}
	close(fd);
}
