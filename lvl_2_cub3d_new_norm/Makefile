NAME 				=	cub3D

SRCS			=	cub3d.c \
				./sources/utils/free.c \
				./sources/utils/utils.c \
				./sources/utils/error.c \
				./sources/utils/ft_split_chars.c \
				./sources/textures/textures.c  \
				./sources/map/map.c \
				./sources/libft/*.c \
				./sources/get_next_line/*.c \
				./sources/file_parsing/parsing.c \
				./sources/file_parsing/map_parsing/map_parsing.c \
				./sources/file_parsing/map_parsing/map_parsing2.c \
				./sources/file_parsing/map_parsing/map_parsing3.c \
				./sources/file_parsing/map_parsing/map_parsing4.c \
				./sources/file_parsing/map_parsing/map_parsing5.c \
				./sources/file_parsing/elements_parsing/f_parsing.c \
				./sources/file_parsing/elements_parsing/we_parsing.c \
				./sources/file_parsing/elements_parsing/so_parsing.c \
				./sources/file_parsing/elements_parsing/s_parsing.c \
				./sources/file_parsing/elements_parsing/r_parsing.c \
				./sources/file_parsing/elements_parsing/no_parsing.c \
				./sources/file_parsing/elements_parsing/ea_parsing.c \
				./sources/file_parsing/elements_parsing/c_parsing.c \
				./sources/events/events.c \
				./sources/events/raycasting/walls.c  \
				./sources/events/raycasting/walls2.c  \
				./sources/events/raycasting/floor_and_ceiling.c  \
				./sources/events/raycasting/sprites.c  \
				./sources/events/raycasting/sprites2.c  \
				./sources/events/raycasting/draw.c  \
				./sources/events/raycasting/bmp.c \
				./sources/events/keys/keys_1.c \
				./sources/events/keys/keys_2.c

INC					=	cub3d.h \
						./sources/libft/libft.h \
						./sources/get_next_line/get_next_line.h \
						./sources/file_parsing/parsing.h \
						./sources/events/events.h \
						./sources/events/raycasting/raycasting.h


CC					=	gcc

CFLAGS				=	-Wall -Wextra -Werror -I./
USE					=	-lbsd -lmlx -lXext -lX11 -lm
LIB					=	./sources/libft/libft.a
all:					$(NAME)

$(NAME):
						make -C ./sources/libft/
						$(CC) $(CFLAGS)  $(LIB) $(SRCS) $(USE) -o $(NAME)
						echo "\033[32m=== COMPILATION CUB3D OK ===\033[0m"

clean:
						make clean -C ./sources/libft/

fclean:
						rm -rf $(NAME)
						echo "\033[34m=== REPERTORY CUB3D CLEANED ===\033[0m"
						make fclean -C ./sources/libft/

re:						fclean all

.PHONY:					clean fclean re all bonus
