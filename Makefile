NAME = miniRT

CC = cc
CFLAGS = -Wall -Werror -Wextra -std=gnu17

LIBFT = libft.a
LIBFT_DIR = libft

VECTORS = vectors.a
VECTORS_DIR = vectors

MLX = libmlx.a
MLX_DIR = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC_DIR = srcs
OBJ_DIR = objs
DEPS_DIR = includes

DEPS = display.h miniRT.h parser.h structures.h utils.h
DEPS := $(addprefix $(DEPS_DIR)/, $(DEPS))


SRCS =	main.c \
		init_display.c render_image.c display_loop.c \
		init_scene.c find_hit.c generate_cam_ray.c


PARSER_SRCS=	check_file.c parse_file.c parse_lightning.c parse_scene.c parse_shapes.c \
				parse_utils.c precompute_transforms.c print_scene.c
PARSER_DIR=	parser
SRCS+= $(addprefix $(PARSER_DIR)/, $(PARSER_SRCS))


UTILS_SRCS=	intersect_cy_caps.c intersect_cy.c intersect_pl.c intersect_sp.c position.c ray.c transform_ray.c
UTILS_DIR=	utils
SRCS+= $(addprefix $(UTILS_DIR)/, $(UTILS_SRCS))


SHADING_SRCS =	compute_color.c normal_at.c shading.c shadows.c
SHADING_DIR= shading
SRCS+= $(addprefix $(SHADING_DIR)/, $(SHADING_SRCS))


OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

RM = rm -rf


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(VECTORS_DIR)/$(VECTORS) $(MLX_DIR)/$(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(VECTORS_DIR)/$(VECTORS) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -I$(DEPS_DIR) -I$(MLX_DIR) -c $< -o $@

$(LIBFT_DIR)/$(LIBFT):
	make -C $(LIBFT_DIR) > /dev/null

$(VECTORS_DIR)/$(VECTORS):
	make -C $(VECTORS_DIR) > /dev/null

$(MLX_DIR)/$(MLX):
	make -C $(MLX_DIR) -f Makefile.mk INC=/usr/include CC="$(CC) -std=gnu17" > /dev/null 2>&1

clean:
	$(RM) $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean > /dev/null
	make -C $(VECTORS_DIR) clean > /dev/null
	make -C $(MLX_DIR) clean > /dev/null

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean > /dev/null
	make -C $(VECTORS_DIR) fclean > /dev/null

re: fclean all

.PHONY: all clean fclean re
