/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksee <aaleksee@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 07:21:45 by aaleksee          #+#    #+#             */
/*   Updated: 2025/01/24 07:21:46 by aaleksee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	*game;

	(void)ac, (void)av;
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		exit(1);
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->set.width, game->set.height, "cub3d");
	(void)game->mlx_win;
	mlx_loop(game->mlx);

	return (0);
}