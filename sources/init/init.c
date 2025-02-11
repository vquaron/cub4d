/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksee <aaleksee@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:49:43 by aaleksee          #+#    #+#             */
/*   Updated: 2025/02/07 13:40:27 by aaleksee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	temp_init(t_game *game);

void	init_main(char **argv, t_game *game)
{
	game = (t_game *)s_alloc(1, sizeof(t_game));
	game->set = (t_set *)s_alloc(1, sizeof(t_set));
	parser_main(argv, game);
	temp_init(game);
}

void	temp_init(t_game *game)
{
	t_set	*set;
	
	set = game->set;

	game->mlx = mlx_init();
    game->mlx_win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3D");
    set->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    set->addr = mlx_get_data_addr(set->img, &set->bpp, &set->line_length, &set->endian);
    
    set->posX = 4.5;
    set->posY = 7.5;

	set->dirX = 1;
	set->dirY = 0;
	set->planeX = 0;
	set->planeY = 0.66;

    // set->dirX = 0;
    // set->dirY = -1;
    // set->planeX = 0.66;
    // set->planeY = 0;

    set->map1 = &map;
	set->w = 0;
	set->a = 0;
	set->s = 0;
	set->d = 0;
    set->pitch = 0;

	mlx_hook(game->mlx_win, 2, 1L<<0, key_press, game);
	mlx_hook(game->mlx_win, 3, 1L<<1, key_release, game);
    mlx_hook(game->mlx_win, 6, 1L<<6, mouse_move, game);
    mlx_loop_hook(game->mlx, render_next_frame, game);
    mlx_loop(game->mlx);
}
