# Detect OS
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
    MLX_DIR = minilibx_opengl
    LFLAGS  = -Wall -Wextra -Werror -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -framework OpenGL -framework AppKit
else
    MLX_DIR = minilibx-linux
    LFLAGS  = -Wall -Wextra -Werror -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lXext -lX11 -lm -lbsd
endif

# Executable file
NAME		=	minirt

# Source files
SRCS		=	src/main.c	$(wildcard src/*/*.c)

# Object files
OBJS		=	$(SRCS:.c=.o)

# Compiler
CC			=	cc

# Libft
LIBFT_DIR	=	libft
LIBFT_NAME	=	libft.a
LIBFT		=	$(LIBFT_DIR)/$(LIBFT_NAME)

# Minilibx
MLX_NAME	=	libmlx.a
MLX			=	$(MLX_DIR)/$(MLX_NAME)

# Compilation flags
DEBUG		=	-fsanitize=address
CFLAGS		=	-Wall -Wextra -Werror -I$(MLX_DIR) -I$(LIBFT_DIR) -I.

# Remove command
RM			=	rm -f

ifeq ($(filter debug,$(MAKECMDGOALS)),debug)
	CFLAGS	+=	$(DEBUG)
	LFLAGS	+=	$(DEBUG)
endif

# Compilation rules
.DEFAULT_GOAL	=	all

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

%.o: %.c
	$(CC) -o $@ $(CFLAGS) -c $<

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

all: $(NAME)

debug: $(NAME)

.PHONY: all clean fclean re debug