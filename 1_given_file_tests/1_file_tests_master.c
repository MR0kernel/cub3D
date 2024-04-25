/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_file_tests_master.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:22:45 by guilrodr          #+#    #+#             */
/*   Updated: 2023/12/09 19:15:08 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	perform_file_tests(t_master *master)
{
	is_the_file_valid(master);
	map_stock_master(master);
	is_closed(master, master->map.original_map);
	valid_objects_check(master, master->map.original_map);
	is_solvable(master);
}
