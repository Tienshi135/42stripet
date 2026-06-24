NAME    = cub3D
src_dir = ./src
obj_dir = ./obj
DEBUG  ?= 0

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

CC       = gcc
CFLAGS   = -Wall -Werror -Wextra -g3
INCLUDES = -I ./include -I ./$(MLX_DIR)
LDFLAGS  = -L ./libft -L ./$(MLX_DIR)
LDLIBS   = -lmlx -lft $(MLX_FLAGS)
DB       = -DDEBUG=$(DEBUG)

SRCS  = $(shell find $(src_dir) -name "*.c")
OBJS  = $(addprefix $(obj_dir)/,$(notdir $(SRCS:.c=.o)))
TOTAL = $(words $(OBJS))

all: $(NAME)

debug: fclean
	@$(MAKE) DEBUG=1

debug2: fclean
	@$(MAKE) DEBUG=2

$(NAME): libft/libft.a $(MLX_LIB) $(OBJS)
	@printf "  \033[0;34m[LD]\033[0m  Linking %s\n" "$@"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LDFLAGS) $(LDLIBS) $(RPATH) -o $@
	@$(MAKE) --no-print-directory compilation_success

$(obj_dir)/%.o: $(src_dir)/*/%.c | $(obj_dir)
	@N=$$(ls $(obj_dir)/*.o 2>/dev/null | wc -l | tr -d '[:space:]'); \
	 printf "  \033[0;32m[%3d%%]\033[0m  Compiling %s\n" \
	        "$$(( (N + 1) * 100 / $(TOTAL) ))" "$<"
	@$(CC) $(CFLAGS) $(INCLUDES) $(DB) -c $< -o $@

$(obj_dir)/%.o: $(src_dir)/%.c | $(obj_dir)
	@N=$$(ls $(obj_dir)/*.o 2>/dev/null | wc -l | tr -d '[:space:]'); \
	 printf "  \033[0;32m[%3d%%]\033[0m  Compiling %s\n" \
	        "$$(( (N + 1) * 100 / $(TOTAL) ))" "$<"
	@$(CC) $(CFLAGS) $(INCLUDES) $(DB) -c $< -o $@

$(obj_dir):
	@mkdir -p $(obj_dir)

libft/libft.a:
	@$(MAKE) --no-print-directory -C libft

$(MLX_DIR)/libmlx.a:
	@$(MAKE) --no-print-directory -C $(MLX_DIR)

$(MLX_DIR)/libmlx.dylib:
	@$(MAKE) --no-print-directory -C $(MLX_DIR)

clean:
	@rm -rf $(obj_dir)
	@$(MAKE) --no-print-directory -C libft clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C libft fclean
	@$(MAKE) --no-print-directory -C $(MLX_DIR) clean

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

re: fclean all

.PHONY: all clean fclean re debug debug2 compilation_success
