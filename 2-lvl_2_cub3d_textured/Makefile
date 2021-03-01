NAME = cube.a

SOURCES = 	teste.c\

SOURCES_O = teste.o\

OBJS = $(SOURCES:.c=.o)

CC = gcc
RM = rm -f
FLAGS = -c -Wall -Wextra -Werror
INCLUDES = -I./includes

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@


all : $(NAME)

$(NAME) :	$(OBJS)
			$(CC) -Lmlx_linux -lmlx_linux -L/usr/local/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean :
			$(MAKE) clean -C ./libft
			$(RM) $(SOURCES_O)
			$(RM) $(OBJS)

fclean :
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)

re :		fclean all

bonus : all
