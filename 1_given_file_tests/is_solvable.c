/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_solvable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:43:36 by guilrodr          #+#    #+#             */
/*   Updated: 2023/12/10 13:10:51 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**malloc_map_for_test(t_master *master);
static char	**copy_map(t_master *master, char **map);
static int	map_recursive_validation(t_master *master, \
										char **map, int player_x, int player_y);
static void	test_validation(t_master *master, char **map_test);

void	is_solvable(t_master *master)
{
	char	**map_test;

	map_test = copy_map(master, master->map.original_map);
	map_recursive_validation(master, map_test, \
							master->player.y, master->player.x);
	test_validation(master, map_test);
	free_map(map_test, master->map.map_size_y);
}

static char	**malloc_map_for_test(t_master *master)
{
	char	**map_test;
	size_t	y;

	y = 0;
	map_test = malloc(sizeof(char *) * master->map.map_size_y + 1);
	if (!map_test)
		basic_error_handler(master, 6);
	while (y < master->map.map_size_y)
	{
		map_test[y] = malloc(sizeof(char) * master->map.map_size_x + 1);
		if (!map_test[y])
			basic_error_handler(master, 6);
		y++;
	}
	return (map_test);
}

static char	**copy_map(t_master *master, char **map)
{
	char	**map_test;
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	map_test = malloc_map_for_test(master);
	while (y < master->map.map_size_y)
	{
		while (x < master->map.map_size_x)
		{
			map_test[y][x] = map[y][x];
			x++;
		}
		map_test[y][x] = '\0';
		x = 0;
		y++;
	}
	return (map_test);
}

static int	map_recursive_validation(t_master *master, char **map, \
										int player_x, int player_y)
{
	if (map[player_x][player_y] == 'D' || map[player_x][player_y] == '1')
		return (0);
	if (map[player_x][player_y] == 'E')
	{
		map[player_x][player_y] = 'M';
		return (0);
	}
	map[player_x][player_y] = 'D';
	return (map_recursive_validation(master, map, player_x + 1, player_y) || \
			map_recursive_validation(master, map, player_x - 1, player_y) || \
			map_recursive_validation(master, map, player_x, player_y + 1) || \
			map_recursive_validation(master, map, player_x, player_y - 1));
}

static void	test_validation(t_master *master, char **map_test)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < master->map.map_size_y)
	{
		while (x < master->map.map_size_x)
		{
			if (map_test[y][x] == 'C')
			{
				free_map(map_test, master->map.map_size_y);
				second_class_error_handler(master, 7);
			}
			else if (map_test[y][x] == 'E')
			{
				free_map(map_test, master->map.map_size_y);
				second_class_error_handler(master, 8);
			}
			x++;
		}
		x = 0;
		y++;
	}
}
