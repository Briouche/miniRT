NAME = miniRT

LIBFT = libft.a
LIBFT_DIR = libft

VECTORS = vectors.a
VECTORS_DIR = vectors

MLX_DIR_LINUX = ./minilibx-linux
MLX_LIB_LINUX = libmlx_Linux.a

MLX_DIR_MAC = ./minilibx-mac
MLX_LIB_MAC = libmlx.dylib

LD_FLAGS_MAC = $(MLX_LIB_MAC) -framework Metal -framework MetalKit -framework Cocoa
LD_FLAGS_LINUX = -L$(MLX_DIR_LINUX) $(MLX_LIB_LINUX) -lXext -lX11 -lz -lbsd

OS:= $(shell uname -s)
ifeq ($(OS), Linux)
	MLX_DIR= $(MLX_DIR_LINUX)
	MLX_LIB= $(MLX_LIB_LINUX)
	LD_FLAGS= $(LD_FLAGS_LINUX)
else
	MLX_DIR= $(MLX_DIR_MAC)
	MLX_LIB= $(MLX_LIB_MAC)
	LD_FLAGS= $(LD_FLAGS_MAC)
endif

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(MLX_DIR) -Iincludes

SRC_DIR = srcs
OBJ_DIR = objs
DEPS_DIR = includes

SRCS =	main.c cannon_ball.c draw_clock.c \
		init_display.c render_image.c display_loop.c \
		ft_ato_.c \
		parser/parsing.c parser/parse_scene.c \
		parser/parse_lightning.c parser/parse_shapes.c parser/parse_utils.c parser/print_scene.c \
		utils/ray.c utils/intersect.c utils/position.c utils/sphere.c
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

DEPS = miniRT.h structures.h
DEPS := $(addprefix $(DEPS_DIR)/, $(DEPS))

RM = rm -f

all: $(NAME)


$(NAME): $(OBJS) $(LIBFT) $(VECTORS) $(MLX_LIB)
	$(CC) $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(VECTORS_DIR)/$(VECTORS) $(LD_FLAGS) -lm -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


$(LIBFT):
	cd $(LIBFT_DIR) ; make > /dev/null

$(VECTORS):
	cd $(VECTORS_DIR) ; make > /dev/null

$(MLX_LIB):
ifeq ($(OS), Linux)
	$(MAKE) libx_linux
else
	$(MAKE) libx_mac
endif

libx_linux:
	cd $(MLX_DIR_LINUX) ; make > /dev/null 2>&1
	cp $(MLX_DIR_LINUX)/$(MLX_LIB_LINUX) .
	cd $(MLX_DIR_LINUX) ; make clean > /dev/null

libx_mac:
	cd $(MLX_DIR_MAC) ; make > /dev/null 2>&1
	cp $(MLX_DIR_MAC)/$(MLX_LIB_MAC) .
	cd $(MLX_DIR_MAC) ; make fclean > /dev/null


clean:
	$(RM) -r $(OBJ_DIR)
	cd $(LIBFT_DIR) ; make clean > /dev/null
	cd $(VECTORS_DIR) ; make clean > /dev/null

fclean: clean
	$(RM) $(NAME)
	$(RM) $(MLX_LIB)
	cd $(LIBFT_DIR) ; make fclean > /dev/null
	cd $(VECTORS_DIR) ; make fclean > /dev/null

re: fclean all

.PHONY: all clean libx_linux libx_mac fclean re