/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ends_with_ber.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:09:04 by guilrodr          #+#    #+#             */
/*   Updated: 2023/12/09 11:55:38 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_the_file_valid(t_master *master)
{
	size_t	index;

	index = str_len(master->given_map);
	while (master->given_map[index] && master->given_map[index] != '.')
		index++;
	if (master->given_map[(index - 3)] != 'b' || \
		master->given_map[(index - 2)] != 'e' || \
		master->given_map[(index - 1)] != 'r' || \
		master->given_map[(index - 4)] != '.')
	{
		basic_error_handler(master, 2);
	}
	if (open(master->given_map, O_RDONLY, 0) == -1)
	{
		basic_error_handler(master, 3);
	}
}
