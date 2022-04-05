NAME	=	so_long


SRCS	=	src/so_long.c		\
			src/parser_check.c	\
			src/parser_init.c	\
			src/parser_error.c	\
			src/move_player.c	\
			src/move_left_right.c \
			src/move_up_down.c

SRCS_B	=	src_b/so_long_b.c		\
			src_b/parser_check_b.c	\
			src_b/parser_init_b.c	\
			src_b/parser_error_b.c	\
			src_b/move_player_b.c	\
			src_b/move_left_right_b.c \
			src_b/move_up_down_b.c	\
			src_b/move_enemy_b.c

OBJ		=	$(SRCS:%.c=%.o)

OBJ_B	=	$(SRCS_B:%.c=%.o)

LIB		=	ft_printf/libftprintf.a libft/libft.a minilibx/libmlx.a 

HEADER	=	so_long.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

RM		= rm -rf

MLX 	= -framework OpenGL -framework AppKit -lmlx

.PHONY:		all	clean	fclean	re	bonus	libft ft_printf

all:		ft_printf libft mlx $(NAME)

libft:
			@$(MAKE) -C libft/
mlx:
			@$(MAKE) -C minilibx/
ft_printf:		
			@$(MAKE) -C ft_printf/

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) $(LIB) $(MLX) -o $(NAME)
			
%.o :		%.c $(INCLUDE)$(HEADER)
			$(CC) $(FLAGS)  -c $< -o $@ -I $(INCLUDE)

bonus:		ft_printf mlx libft $(OBJ_B)
			$(CC) $(FLAGS) $(OBJ_B) $(LIB) $(MLX) -o $(NAME)
			

clean:
			@$(RM) $(OBJ) $(OBJ_B)
			@$(MAKE) -C libft/ clean
			@$(MAKE) -C minilibx/ clean
			@$(MAKE) -C ft_printf/ clean
			
fclean:		clean
			@$(MAKE) -C libft/ fclean
			@$(MAKE) -C ft_printf/ fclean
			@$(RM) $(NAME)
			

re:			fclean all
			
