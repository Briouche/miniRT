NAME= vectors.a

CC= cc
CFLAGS= -Wall -Werror -Wextra

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	LDFLAGS = -lm
else
	LDFLAGS =
endif

SRCS=	is_equal.c is_point.c is_vector.c \
		op_cross.c op_dot.c op_magnitude.c op_minus.c op_multi.c op_normalise.c op_opposite.c op_plus.c \
		add_colors.c multi_colors.c multi_scalar_colors.c sub_colors.c \
		point.c vector.c vec_color.c

OBJ_DIR= objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

DEPS= vectors.h

RM= rm -f
AR = ar crs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $(OBJS)

$(OBJ_DIR)/%.o: %.c $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@ $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) -r $(OBJ_DIR)
	

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re