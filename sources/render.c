#include "cub3d.h"

void draw_map(t_set *set)
{
    int y, x, i, j, color;

    for (y = 0; y < MAP_HEIGHT; y++)
    {
        for (x = 0; x < MAP_WIDTH; x++)
        {
            color = ((*set->map1)[y][x] == 1) ? 0xFFFFFF : 0x000000;

            for (i = 0; i < TILE_SIZE; i++)
            {
                for (j = 0; j < TILE_SIZE; j++)
                {
                    if (i == 0 || j == 0 || i == TILE_SIZE - 1 || j == TILE_SIZE - 1)
						my_mlx_pixel_put(set, x * TILE_SIZE + j, y * TILE_SIZE + i, 0xFF0000);
					else if ((*set->map1)[y][x] == 1)
						my_mlx_pixel_put(set, x * TILE_SIZE + j, y * TILE_SIZE + i, color);
                }
            }
        }
    }
}

void my_mlx_pixel_put(t_set *set, int x, int y, int color)
{
    char *dst = set->addr + (y * set->line_length + x * (set->bpp / 8));
    *(unsigned int*)dst = color;
}

void fill_background(t_set *set, int color)
{
	int x;
	int y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			my_mlx_pixel_put(set, x, y, color);
			y++;
		}
		x++;
	}
}

int render_next_frame(t_game *game)
{
	t_set *set;

	set = game->set;
	move_player(set);
    fill_background(set, 0x444444);
	draw_map(set);
    draw_scene(set);
	print_player(set, 0x00FF00);
    mlx_put_image_to_window(game->mlx, game->mlx_win, set->img, 0, 0);
    return (0);
}

void draw_scene(t_set *set)
{
    int x;
    for (x = 0; x < SCENE_AREA_WIDTH; x++)
    {
        double cameraX = 2 * x / (double)SCENE_AREA_WIDTH - 1;
        double rayDirX = set->dirX + set->planeX * cameraX;
        double rayDirY = set->dirY + set->planeY * cameraX;

        int mapX = (int)set->posX;
        int mapY = (int)set->posY;

        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

        double sideDistX;
        double sideDistY;
        int stepX;
        int stepY;

        if (rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (set->posX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - set->posX) * deltaDistX;
        }
        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (set->posY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - set->posY) * deltaDistY;
        }

        int hit = 0;
        int side;
        while (hit == 0)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if ((*set->map1)[mapY][mapX] > 0)
                hit = 1;
        }

        double perpWallDist;
        if (side == 0)
            perpWallDist = (mapX - set->posX + (1 - stepX) / 2.0) / rayDirX;
        else
            perpWallDist = (mapY - set->posY + (1 - stepY) / 2.0) / rayDirY;

        int lineHeight = (int)(HEIGHT / perpWallDist);

        int drawStart = -lineHeight / 2 + HEIGHT / 2;
        if (drawStart < 0)
            drawStart = 0;
        int drawEnd = lineHeight / 2 + HEIGHT / 2;
        if (drawEnd >= HEIGHT)
            drawEnd = HEIGHT - 1;

        int color;
        switch ((*set->map1)[mapY][mapX])
        {
            case 1: color = 0xFF0000; break;
            case 2: color = 0x00FF00; break;
            case 3: color = 0x0000FF; break;
            case 4: color = 0xFFFFFF; break;
            default: color = 0xFFFF00; break;
        }
        if (side == 1)
            color = color / 2;

        int y;
        for (y = drawStart; y < drawEnd; y++)
        {
            my_mlx_pixel_put(set, MAP_AREA_WIDTH + x, y, color);
        }
    }
}
