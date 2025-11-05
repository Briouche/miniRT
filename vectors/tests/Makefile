NAME= tests_vectors

LIBFT =
LIBFT_DIR =

VECTORS = vectors.a
VECTORS_DIR = ..

CC= cc
CFLAGS= -Wall -Werror -Wextra

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	LDFLAGS = -lm
else
	LDFLAGS =
endif

SRCS=	main.c prints.c \
		test_matrices_multi.c test_matrix_reductions.c \
		test_translation.c test_shearing.c test_rotations.c

OBJ_DIR= objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

DEPS= tests.h

RM= rm -f
AR = ar crs

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(VECTORS_DIR)/$(VECTORS) -o $(NAME) $(CFLAGS) $(LDFLAGS)

$(OBJ_DIR)/%.o: %.c $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	$(RM) -r $(OBJ_DIR)
	

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re