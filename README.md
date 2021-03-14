# lvl_2_cub3d

Ficheiros já organizados. Norminette é mais facil agora.
Começar a ver agora os requisitos e tentar fazer-los.

gcc cub3d.c ./sources/utils/error.c ./sources/events/events.c ./sources/textures/textures.c  ./sources/map/map.c ./sources/events/raycasting/sprites.c ./sources/events/raycasting/walls.c ./sources/events/raycasting/draw.c ./sources/events/raycasting/floor_and_ceiling.c  ./sources/events/keys/keys_1.c ./sources/events/keys/keys_2.c -lbsd -lmlx -lXext -lX11 -lm

cc -I  /usr/local/lib -lmlx -framework OpenGL -framework AppKit  main.c error.c events.c images.c map.c raycasting.c textures.c

gcc -lmlx -framework AppKit main.c error.c events.c images.c map.c raycasting.c textures.c

gcc -lmlx -framework OpenGL -framework AppKit main.c error.c events.c images.c map.c raycasting.c textures.c


https://github.com/l-yohai/cub3d/tree/master/mlx_example

https://lodev.org/cgtutor/raycasting.html

https://github.com/taelee42/mlx_example

