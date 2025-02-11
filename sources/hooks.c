/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksee <aaleksee@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:53:11 by aaleksee          #+#    #+#             */
/*   Updated: 2025/02/04 16:26:35 by aaleksee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_press(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->mlx);
		exit(0);
	}
	if (keycode == 13 || keycode == 65362 || keycode == 119)
		game->set->w = 1;
	if (keycode == 0 || keycode == 65361 || keycode == 97)
		game->set->a = 1;
	if (keycode == 1 || keycode == 65364 || keycode == 115)
		game->set->s = 1;
	if (keycode == 2 || keycode == 65363 || keycode == 100)
		game->set->d = 1;
	return (0);
}

int key_release(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 65362 || keycode == 119)
		game->set->w = 0;
	if (keycode == 0 || keycode == 65361 || keycode == 97)
		game->set->a = 0;
	if (keycode == 1  || keycode == 65364 || keycode == 115)
		game->set->s = 0;
	if (keycode == 2 || keycode == 65363 || keycode == 100)
		game->set->d = 0;
	return (0);
}

int mouse_move(int x, int y, t_game *game)
{
    static int prevX = WIDTH / 2 + MAP_AREA_WIDTH / 2;
    static int prevY = HEIGHT / 2;

    double sense = 0.05;
    double rotSpeed = (x - prevX) * sense;
    double oldDirX = game->set->dirX;
    game->set->dirX = game->set->dirX * cos(-rotSpeed) - game->set->dirY * sin(-rotSpeed);
    game->set->dirY = oldDirX * sin(-rotSpeed) + game->set->dirY * cos(-rotSpeed);
    double oldPlaneX = game->set->planeX;
    game->set->planeX = game->set->planeX * cos(-rotSpeed) - game->set->planeY * sin(-rotSpeed);
    game->set->planeY = oldPlaneX * sin(-rotSpeed) + game->set->planeY * cos(-rotSpeed);

    // double pitchSpeed = (y - prevY) * sense;
    game->set->pitch = y - prevY;
    // if (game->set->pitch > HEIGHT)
    //     game->set->pitch = HEIGHT / 4;
    // if (game->set->pitch < -HEIGHT)
    //     game->set->pitch = -HEIGHT / 4;
    mlx_mouse_move(game->mlx_win, WIDTH / 2 + MAP_AREA_WIDTH / 2, HEIGHT / 2);
    prevX = WIDTH / 2 + MAP_AREA_WIDTH / 2;
    prevY = HEIGHT / 2;
    return (0);
}