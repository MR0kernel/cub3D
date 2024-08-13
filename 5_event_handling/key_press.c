/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:11:14 by guilrodr          #+#    #+#             */
/*   Updated: 2024/08/13 22:47:23 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	keypress(int keypressed, t_master *master)
{
	if (keypressed == 119)
		master->player.up = 1;
	if (keypressed == 115)
		master->player.down = 1;
	if (keypressed == 97)
		master->player.left = 1;
	if (keypressed == 100)
		master->player.rigth = 1;
	if (keypressed == XK_Left)
		master->player.rotate_left = 1;
	if (keypressed == XK_Right)
		master->player.rotate_right = 1;
	if (keypressed == 65307)
		end_of_program(master, 0);
	return (keypressed);
}

int	keyrelease(int keypressed, t_master *master)
{
	if (keypressed == 119)
		master->player.up = 0;
	if (keypressed == 115)
		master->player.down = 0;
	if (keypressed == 97)
		master->player.left = 0;
	if (keypressed == 100)
		master->player.rigth = 0;
	if (keypressed == XK_Left)
		master->player.rotate_left = 0;
	if (keypressed == XK_Right)
		master->player.rotate_right = 0;
	return (keypressed);
}
