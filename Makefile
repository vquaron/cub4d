NAME =			cub3D

SRC_PATH =		sources
UTL_PATH =		sources/utils
MLX_PATH =		mlx
LFT_PATH =		libft
OBJ_DIR  =		objects

SRC =	$(SRC_PATH)/cub3d.c

OSRC  = $(SRC:%.c=$(OBJ_DIR)/%.o)
MLX   =	$(MLX_PATH)/libmlx.a
LIBFT = $(LFT_PATH)/libft.a
# INCLUDES = 


CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./includes #-g -fsanitize=thread
MLX_FLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OSRC) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) ${OSRC} $(LIBFT) -I$(MLX_PATH) $(MLX_FLAGS) -o $(NAME)
	@echo "cub3D created"

$(LIBFT):
	@make -C $(LFT_PATH)

$(MLX):
	@make -C $(MLX_PATH)

ex: re
	@./cub3D

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LFT_PATH)
	@make clean -C $(MLX_PATH)
	@echo "Object files cleaned"

fclean: clean
	@rm -rf $(NAME)
	make fclean -C $(LFT_PATH)
	@echo "Executable and libraries cleaned"

re: fclean all

.PHONY: all clean fclean re