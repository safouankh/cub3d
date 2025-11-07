NAME = cub3d
CC = cc
CFLAGS = #-Wall -Wextra -Werror

# ****************| linked libraries |***************
MLX42_DIR = ./MLX42
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a
MLX42_INCLUDE = -I$(MLX42_DIR)/include -I$(MLX42_DIR)/build/include
GLFW_PATH = /goinfre/$(USER)/homebrew
GLFW_LIB = -L$(GLFW_PATH)/lib -lglfw
FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit
MLX_FLAGS = $(MLX42_LIB) $(GLFW_LIB) $(FRAMEWORKS)

# ******************| sources |******************
SRC = ./sources/main.c\
      ./get_next_line/get_next_line.c\
      ./get_next_line/get_next_line_utils.c\
	  ./parsing/parser.c\
	  ./parsing/utils_0.c\
	  ./parsing/utils_1.c\
	  ./parsing/parse_texture.c\
	  ./parsing/parse_ceiling.c\
	  ./parsing/parse_floor.c\
	  ./parsing/parse_map.c\
	  ./events/handel_keys.c\

# ******************| Objects |******************
OBJ = $(SRC:.c=.o)

# ******************| libft |******************
LIBFT = ./libft/libft.a

# ******************| Rules |******************
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	@make -C libft

%.o: %.c
	$(CC) $(CFLAGS) $(MLX42_INCLUDE) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all clean
