NAME	= cub3D

LIBRARY	= -lmlx -lm -lft\
		-L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY)\
		-framework OpenGL -framework AppKit

INCLUDES = -I$(HEADERS_DIRECTORY) -I$(MINILIBX_HEADERS) -I$(LIBFT_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = ./mlx/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

HEADERS_DIRECTORY = ./includes/
HEADERS_LIST = cub3D.h
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SRCS_DIRECTORY = ./src/
SRCS_LIST	= cub3D.c get_next_line.c test_parser.c hook.c utils.c raycasting.c draw.c\
				moves.c mini_map.c mouse.c draw_lov.c
SRCS = $(addprefix $(SRCS_DIRECTORY), $(SRCS_LIST))

OBJS_DIRECTORY = objects/
OBJS_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))
OBJS = $(addprefix $(OBJS_DIRECTORY), $(OBJS_LIST))

CC			= gcc

CFLAGS	= -Wall -Wextra -Werror -g3
# CFLAGS	= -g

all:		${NAME}

$(NAME):	$(LIBFT) $(MINILIBX) $(OBJS_DIRECTORY) $(OBJS)
			@$(CC) $(CFLAGS) $(LIBRARY) $(INCLUDES) $(OBJS) -o $(NAME)

$(OBJS_DIRECTORY):
			mkdir -p $(OBJS_DIRECTORY)

$(OBJS_DIRECTORY)%.o : $(SRCS_DIRECTORY)%.c $(HEADERS)
			@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
			@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(MINILIBX):
			@$(MAKE) -sC $(MINILIBX_DIRECTORY) 2>/dev/null
		

clean:
			@rm -rf $(OBJS_DIRECTORY)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus

# clean:
# 			@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
# 			@$(MAKE) -sC $(MINILIBX_DIRECTORY) clean
# 			@rm -rf $(OBJS_DIRECTORY)

# fclean:		clean
# 			@rm -f $(LIBFT)
# 			@rm -f $(MINILIBX)
# 			@rm -f $(NAME)