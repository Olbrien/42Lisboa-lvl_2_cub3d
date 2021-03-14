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

SRCS_B			=	cub3d_bonus.c \
				./sources_bonus/utils/free.c \
				./sources_bonus/utils/utils.c \
				./sources_bonus/utils/error.c \
				./sources_bonus/utils/ft_split_chars.c \
				./sources_bonus/textures/textures.c  \
				./sources_bonus/map/map.c \
				./sources_bonus/libft/*.c \
				./sources_bonus/get_next_line/*.c \
				./sources_bonus/file_parsing/parsing.c \
				./sources_bonus/file_parsing/map_parsing/map_parsing.c \
				./sources_bonus/file_parsing/map_parsing/map_parsing2.c \
				./sources_bonus/file_parsing/map_parsing/map_parsing3.c \
				./sources_bonus/file_parsing/map_parsing/map_parsing4.c \
				./sources_bonus/file_parsing/map_parsing/map_parsing5.c \
				./sources_bonus/file_parsing/elements_parsing/f_parsing.c \
				./sources_bonus/file_parsing/elements_parsing/we_parsing.c \
				./sources_bonus/file_parsing/elements_parsing/so_parsing.c \
				./sources_bonus/file_parsing/elements_parsing/s_parsing.c \
				./sources_bonus/file_parsing/elements_parsing/r_parsing.c \
				./sources_bonus/file_parsing/elements_parsing/no_parsing.c \
				./sources_bonus/file_parsing/elements_parsing/ea_parsing.c \
				./sources_bonus/file_parsing/elements_parsing/c_parsing.c \
				./sources_bonus/events/events.c \
				./sources_bonus/events/raycasting/walls.c  \
				./sources_bonus/events/raycasting/walls2.c  \
				./sources_bonus/events/raycasting/floor_and_ceiling.c  \
				./sources_bonus/events/raycasting/sprites.c  \
				./sources_bonus/events/raycasting/sprites2.c  \
				./sources_bonus/events/raycasting/draw.c  \
				./sources_bonus/events/raycasting/bmp.c \
				./sources_bonus/events/keys/keys_1.c \
				./sources_bonus/events/keys/keys_2.c

INC_B					=	cub3d_bonus.h \
						./sources_bonus/libft/libft.h \
						./sources_bonus/get_next_line/get_next_line.h \
						./sources_bonus/file_parsing/parsing.h \
						./sources_bonus/events/events.h \
						./sources_bonus/events/raycasting/raycasting.h


CC					=	gcc

CFLAGS				=	-Wall -Wextra -Werror -I./
USE					=	-lbsd -lmlx -lXext -lX11 -lm
LIB					=	./sources/libft/libft.a
LIB_BONUS			=	./sources_bonus/libft/libft.a
all:					$(NAME)

$(NAME):
						make -C ./sources/libft/
						$(CC) $(CFLAGS)  $(LIB) $(SRCS) $(USE) -o $(NAME)

clean:
						make clean -C ./sources/libft/
						make clean -C ./sources_bonus/libft/

fclean:
						rm -rf $(NAME)
						make fclean -C ./sources/libft/
						make fclean -C ./sources_bonus/libft/

re:						fclean all

bonus:
						make -C ./sources_bonus/libft/
						$(CC) $(CFLAGS)  $(LIB_BONUS) $(SRCS_B) $(USE) -o $(NAME)

.PHONY:					clean fclean re all bonus
