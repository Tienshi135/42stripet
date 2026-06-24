###VARIABLES###

# name of the executable
NAME = cub3D

# variables
src_dir = ./src
obj_dir = ./obj
DEBUG ?= 0

# OS detection
UNAME := $(shell uname -s)

ifeq ($(UNAME), Darwin)
    MLX_DIR   = mlx_macos
    MLX_LIB   = $(MLX_DIR)/libmlx.dylib
    MLX_FLAGS = -framework Cocoa -framework Metal -framework AppKit
    RPATH     = -Wl,-rpath,@executable_path/$(MLX_DIR)
else
    MLX_DIR   = mlx_linux
    MLX_LIB   = $(MLX_DIR)/libmlx.a
    MLX_FLAGS = -lXext -lX11 -lm -lz -lXfixes
    RPATH     =
endif

# compilator and compilation flags
CC       = gcc
CFLAGS   = -Wall -Werror -Wextra -g3
INCLUDES = -I ./include -I ./$(MLX_DIR)
LDFLAGS  = -L ./libft -L ./$(MLX_DIR)
LDLIBS   = -lmlx -lft $(MLX_FLAGS)
DB       = -DDEBUG=$(DEBUG)

# source files (recursively find all .c files)
SRCS = $(shell find $(src_dir) -name "*.c")
OBJS = $(addprefix $(obj_dir)/,$(notdir $(SRCS:.c=.o)))

###RULES###
all: $(NAME)

debug: fclean
	@$(MAKE) DEBUG=1

debug2: fclean
	@$(MAKE) DEBUG=2

$(NAME): libft/libft.a $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LDFLAGS) $(LDLIBS) $(RPATH) -o $@
	@$(MAKE) compilation_success

# Create object files from source files
$(obj_dir)/%.o: $(src_dir)/*/%.c | $(obj_dir)
	$(CC) $(CFLAGS) $(INCLUDES) $(DB) -c $< -o $@

$(obj_dir)/%.o: $(src_dir)/%.c | $(obj_dir)
	$(CC) $(CFLAGS) $(INCLUDES) $(DB) -c $< -o $@

# Create object directory
$(obj_dir):
	mkdir -p $(obj_dir)

# Build libft
libft/libft.a:
	@$(MAKE) -C libft

# Build mlx
$(MLX_DIR)/libmlx.a:
	@$(MAKE) -C $(MLX_DIR)

$(MLX_DIR)/libmlx.dylib:
	@$(MAKE) -C $(MLX_DIR)

# Clean object files
clean:
	rm -rf $(obj_dir)
	$(MAKE) -C libft clean

# Clean everything
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C $(MLX_DIR) clean

compilation_success:
	@echo "╔╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╗"
	@echo "╠╬╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╬╣"
	@echo "╠╣ ██████╗██╗   ██╗██████╗ ██████╗ ██████╗ ╠╣"
	@echo "╠╣██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗╠╣"
	@echo "╠╣██║     ██║   ██║██████╔╝ █████╔╝██║  ██║╠╣"
	@echo "╠╣██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║╠╣"
	@echo "╠╣╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝╠╣"
	@echo "╠╣ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╠╣"
	@echo "╠╬╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╬╣"
	@echo "╚╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╝"

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
