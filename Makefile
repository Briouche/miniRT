NAME = miniRT

MLX_DIR_LINUX = ./minilibx-linux
MLX_LIB_LINUX = libmlx_Linux.a

MLX_DIR_MAC = ./minilibx-mac
MLX_LIB_MAC = libmlx.dylib

LD_FLAGS_MAC = $(MLX_LIB_MAC) -framework Metal -framework MetalKit -framework Cocoa
LD_FLAGS_LINUX = -L$(MLX_DIR_LINUX) $(MLX_LIB_LINUX) -lXext -lX11 -lm -lz -lbsd

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
CFLAGS = -Wall -Werror -Wextra -I$(MLX_DIR) -Iincludes -g

SRC_DIR = srcs
OBJ_DIR = objs
DEPS_DIR = includes

SRCS =	main.c free.c \
		ft_ato_.c ft_atoi.c ft_calloc.c ft_split.c gnl.c is.c strings.c \
		parser_functions.c parsing.c tokenization.c
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

DEPS = miniRT.h
RM = rm -f

all: $(NAME)


$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(OBJS) $(LD_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS_DIR)/$(DEPS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


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

fclean: clean
	$(RM) $(NAME)
	$(RM) $(MLX_LIB)

re: fclean all

.PHONY: all clean libx_linux libx_mac fclean re