NAME =			cub3D

SRC_PATH =		sources
INI_PATH =		sources/init
MEM_PATH =		sources/memory_managment
UTL_PATH =		sources/utils
INC_PATH =		includes
LIB_PATH =		libraries
LFT_PATH =		libraries/libft
OBJ_DIR  =		objects

SRC	=	main.c \
		$(SRC_PATH)/render.c \
		$(SRC_PATH)/map.c \
		$(SRC_PATH)/hooks.c \
		$(INI_PATH)/init.c \
		$(INI_PATH)/parser.c \
		$(INI_PATH)/validator.c \
		$(INI_PATH)/validator2.c \
		$(MEM_PATH)/allocator.c \
		$(UTL_PATH)/general_utils.c


ifeq ($(shell uname),Darwin)
 MLX_PATH = $(LIB_PATH)/Minilibx
 MLX_FLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
else
 MLX_PATH = $(LIB_PATH)/Minilibx_l
 MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm
endif

OSRC  = 	$(SRC:%.c=$(OBJ_DIR)/%.o)
MLX   =		$(MLX_PATH)/libmlx.a
LIBFT = 	$(LFT_PATH)/libft.a
INCLUDES = 	$(INC_PATH)/cub3d.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./includes -g -fsanitize=thread

all: $(NAME)

$(NAME): $(OSRC) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) ${OSRC} $(LIBFT) -I$(MLX_PATH) $(MLX_FLAGS) -o $(NAME)
	@echo "cub3D created"

$(LIBFT):
	@echo "Libft created"
	@make -C $(LFT_PATH)

$(MLX):
	@echo "MLX created"
	@make -C $(MLX_PATH)

ex: $(NAME)
	@./cub3D

$(OBJ_DIR)/%.o: %.c $(INCLUDES) Makefile
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LFT_PATH)
	@make clean -C $(MLX_PATH)
	@echo "Object files cleaned"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LFT_PATH)
	@echo "Executable and libraries cleaned"

re: fclean all

.PHONY: all clean fclean re ex