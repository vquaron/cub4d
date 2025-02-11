#ifndef CUB3D_H
# define CUB3D_H

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <math.h>
// #include "../libraries/libft/libft.h"
// #include "../libraries/Minilibx/mlx.h"

// typedef struct	s_data
// {
// 	void	*mlx;
// 	void	*win;
// }			t_set;

// int		render_next_frame(t_set *set);
// #endif

# include "../libraries/Minilibx/mlx.h"
# include "../libraries/libft/libft.h"
# include "map.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdbool.h>

# define WIDTH 1600
# define HEIGHT 800
# define TILE_SIZE 64
# define MAP_AREA_WIDTH (MAP_WIDTH * TILE_SIZE)
# define MAP_AREA_HEIGHT (MAP_HEIGHT * TILE_SIZE)
# define SCENE_AREA_WIDTH (WIDTH - MAP_AREA_WIDTH)
# define SCENE_AREA_HEIGHT HEIGHT

typedef enum e_tex_type
{
	NO,
	SO,
	WE,
	EA,
	TEX_COUNT
}			t_tex_type;

typedef struct s_tex
{
	char	*tex_path;

	int		tex_width;
	int		tex_height;

}			t_tex;

typedef struct s_settings
{
	t_tex	texs[4];
	int		*colours;
	int		**map;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;

	double	pitch;
	double posX, posY;
	double dirX, dirY;
	double planeX, planeY;

	int (*map1)[MAP_HEIGHT][MAP_WIDTH];
	int w, a, s, d;
}			t_set;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	t_set	*set;
}			t_game;

void		init_main(char **argv, t_game *game);

// utils
void		exit_fail(char *exit_message);
void		validation_error_msg(char *msg, char *var);
void		full_print(char *str); //del
// end of utils

// memory managment
void		*s_alloc(size_t count, size_t size);
void		*s_realloc(void *ptr, size_t old_size, size_t new_size);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);


// end of MM

void		perform_dda(t_set *set, double rayDirX, double rayDirY, int *mapX,
				int *mapY, int *side);

// render
void		draw_map(t_set *set);
void		my_mlx_pixel_put(t_set *set, int x, int y, int color);
void		fill_background(t_set *set, int color);
int			render_next_frame(t_game *game);
void		draw_scene(t_set *set);

// hooks
int			key_press(int keycode, t_game *game);
int			key_release(int keycode, t_game *game);
int			mouse_move(int x, int y, t_game *game);

void		move_player(t_set *set);
void		print_player(t_set *set, int color);

#endif
