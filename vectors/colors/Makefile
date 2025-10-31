NAME= colors.a

CC= cc
CFLAGS= -Wall -Werror -Wextra -I..

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	LDFLAGS = -lm
else
	LDFLAGS =
endif

SRCS=	color.c \
		add_colors.c multi_colors.c multi_scalar_colors.c sub_colors.c

OBJ_DIR= objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

DEPS= colors.h

RM= rm -f
AR = ar crs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

$(OBJ_DIR)/%.o: %.c $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@ $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) -r $(OBJ_DIR)
	

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re