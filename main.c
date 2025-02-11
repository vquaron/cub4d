#include "cub3d.h"

void move_player(t_set *set)
{
    double moveSpeed = 0.05; // Уменьшенная скорость перемещения
    double newPosX, newPosY;

    if (set->w)
    {
        newPosX = set->posX + set->dirX * moveSpeed;
        newPosY = set->posY + set->dirY * moveSpeed;
        if (newPosX >= 0 && newPosX < MAP_WIDTH && newPosY >= 0 && newPosY < MAP_HEIGHT && (*set->map1)[(int)newPosY][(int)newPosX] == 0)
        {
            set->posX = newPosX;
            set->posY = newPosY;
        }
    }
    if (set->s)
    {
        newPosX = set->posX - set->dirX * moveSpeed;
        newPosY = set->posY - set->dirY * moveSpeed;
        if (newPosX >= 0 && newPosX < MAP_WIDTH && newPosY >= 0 && newPosY < MAP_HEIGHT && (*set->map1)[(int)newPosY][(int)newPosX] == 0)
        {
            set->posX = newPosX;
            set->posY = newPosY;
        }
    }
    if (set->a)
    {
        newPosX = set->posX - set->planeX * moveSpeed;
        newPosY = set->posY - set->planeY * moveSpeed;
        if (newPosX >= 0 && newPosX < MAP_WIDTH && newPosY >= 0 && newPosY < MAP_HEIGHT && (*set->map1)[(int)newPosY][(int)newPosX] == 0)
        {
            set->posX = newPosX;
            set->posY = newPosY;
        }
    }
    if (set->d)
    {
        newPosX = set->posX + set->planeX * moveSpeed;
        newPosY = set->posY + set->planeY * moveSpeed;
        if (newPosX >= 0 && newPosX < MAP_WIDTH && newPosY >= 0 && newPosY < MAP_HEIGHT && (*set->map1)[(int)newPosY][(int)newPosX] == 0)
        {
            set->posX = newPosX;
            set->posY = newPosY;
        }
    }
}

void print_player(t_set *set, int color)
{
    int player = 5;
    int x, y;

    for (x = -player / 2; x < player / 2; x++)
    {
        for (y = -player / 2; y < player / 2; y++)
        {
            my_mlx_pixel_put(set, (int)(set->posX * TILE_SIZE) + x, (int)(set->posY * TILE_SIZE) + y, color);
        }
    }
}

int main(int ac, char **argv)
{
	t_game	*game;

	game = NULL;
	if (ac == 2)
		init_main(argv, game);
	exit_fail("Pass a map with .cub extension");
    
    return (0);
}
