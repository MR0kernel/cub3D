/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:11:14 by guilrodr          #+#    #+#             */
/*   Updated: 2023/12/10 12:13:43 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	keypress(int keypressed, t_master *master)
{
	if (keypressed == 119)
		character_mouvement(master, keypressed);
	if (keypressed == 115)
		character_mouvement(master, keypressed);
	if (keypressed == 97)
		character_mouvement(master, keypressed);
	if (keypressed == 100)
		character_mouvement(master, keypressed);
	if (keypressed == 65307)
		end_of_program(master, 0);
	return (keypressed);
}
