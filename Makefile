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
NAME		=	miniRT

# Source files
SRCS_RT		=	calc_one.c \
				calc_two.c \
				intersect.c \
				intersect_cy.c \
				intersect_cy_two_bases.c \
				intersect_pl.c \
				intersect_sp.c \
				lighting.c \
				ray_dir.c \
				raytracing.c
SRCS_HOOK	=	hook_init.c \
				hook_lst_at.c \
				key_hook_loop.c \
				key_hook_update.c \
				key_hook_update_camera.c \
				key_hook_update_camera_move.c \
				key_hook_update_camera_rotate.c \
				key_hook_update_light.c \
				key_hook_update_light_move.c \
				key_hook_update_obj.c \
				key_hook_update_obj_move.c \
				key_hook_update_obj_resize.c \
				key_hook_update_obj_rotate.c \
				prompt.c \
				prompt_camera.c \
				prompt_elem.c \
				prompt_light.c \
				prompt_object.c \
				rotate.c
SRCS_SET	=	set.c \
				set_cylinder.c \
				set_elem.c \
				set_plane.c \
				set_sphere.c \
				set_utils.c
SRCS_LOOP	=	loop.c
SRCS_UTIL	=	convertible_to_float.c \
				exit.c \
				ft_atof.c
SRCS_WRAP	=	xcalloc.c \
				xclose.c \
				xlstnew.c \
				xmalloc.c \
				xmlx_get_data_addr.c \
				xmlx_init.c \
				xmlx_new_image.c \
				xmlx_new_window.c \
				xopen.c \
				xrealloc.c \
				xsplit.c
SRCS		=	src/main.c	\
				$(addprefix src/raytracing/, $(SRCS_RT)) \
				$(addprefix src/hook/, $(SRCS_HOOK)) \
				$(addprefix src/set/, $(SRCS_SET)) \
				$(addprefix src/loop/, $(SRCS_LOOP)) \
				$(addprefix src/util/, $(SRCS_UTIL)) \
				$(addprefix src/wrap/, $(SRCS_WRAP))

# Object files
OBJS		=	$(SRCS:.c=.o)

# Compiler
CC			=	cc

# Libft
LIBFT_DIR	=	libft
LIBFT_NAME	=	libft.a
LIBFT		=	$(LIBFT_DIR)/$(LIBFT_NAME)

# Minilibx
MLX_NAME	=	libmlx_Linux.a
MLX			=	$(MLX_DIR)/$(MLX_NAME)

# Compilation flags
DEBUG		=	-fsanitize=address
OPTFLAG		=	-O3 -flto
CFLAGS		=	-Wall -Wextra -Werror -I$(MLX_DIR) -I$(LIBFT_DIR) -I. -I%%%%

# Remove command
RM			=	rm -f

ifeq ($(filter debug,$(MAKECMDGOALS)),debug)
	CFLAGS	+=	$(DEBUG)
	LFLAGS	+=	$(DEBUG)
endif

ifeq ($(filter fast,$(MAKECMDGOALS)),fast)
	CFLAGS	+=	$(OPTFLAG)
	LFLAGS	+=	$(OPTFLAG)
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

fast: $(NAME)

.PHONY: all clean fclean re debug fast
