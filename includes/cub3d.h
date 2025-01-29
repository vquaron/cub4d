/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksee <aaleksee@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 07:19:46 by aaleksee          #+#    #+#             */
/*   Updated: 2025/01/24 07:19:47 by aaleksee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../includes/libft.h"

typedef struct s_tex
{
	char		*tex_path;
	int			tex_width;
	int			tex_height;

}				t_tex;

typedef struct s_settings
{
	int			width;
	int			height;
	t_tex		tex[4];
	int			floor_color;
	int			ceiling_color;
}				t_settings;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_settings	set;
}			t_game;

#endif
