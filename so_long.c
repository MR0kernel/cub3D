/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:04:26 by guilrodr          #+#    #+#             */
/*   Updated: 2023/12/10 13:22:37 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int number_of_args, char **args)
{
	t_master	*master;

	master = malloc(sizeof(t_master));
	if (master == NULL)
		basic_error_handler(master, 6);
	init_master_struct(master);
	if (number_of_args != 2)
		basic_error_handler(master, 1);
	master->given_map = args[1];
	perform_file_tests(master);
	master->mlx = mlx_init();
	if (master->mlx == NULL)
		second_class_error_handler(master, 10);
	launch_images(master);
	launch_window(master);
	fifth_class_error_handler(master, 0);
	return (0);
}
