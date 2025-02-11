#include "cub3d.h"

void perform_dda(t_set *set, double rayDirX, double rayDirY, int *mapX, int *mapY, int *side)
{
    int stepX = (rayDirX < 0) ? -1 : 1;
    int stepY = (rayDirY < 0) ? -1 : 1;
    
    double deltaDistX = fabs(1 / rayDirX);
    double deltaDistY = fabs(1 / rayDirY);

    double sideDistX = (rayDirX < 0) ? (set->posX - *mapX) * deltaDistX : (*mapX + 1.0 - set->posX) * deltaDistX;
    double sideDistY = (rayDirY < 0) ? (set->posY - *mapY) * deltaDistY : (*mapY + 1.0 - set->posY) * deltaDistY;

    while (set->map1[*mapY][*mapX] == 0)
    {
        if (sideDistX < sideDistY)
        {
            sideDistX += deltaDistX;
            *mapX += stepX;
            *side = 0;
        }
        else
        {
            sideDistY += deltaDistY;
            *mapY += stepY;
            *side = 1;
        }
    }
}