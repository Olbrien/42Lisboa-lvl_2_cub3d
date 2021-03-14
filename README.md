# cub3d

###### <i>Recent Update on 14/03/2021.</i>
Done everything I could. Waiting for upload.

###### <i>Old Update on 13/03/2021.</i>
Done with Norminette v3.

**** Pictures ****

![GitHub Logo](/extras/images/picture_1.png)\
![GitHub Logo](/extras/images/picture_2.png)

**** Tests ****

[cub3D_leaks_maps_tester](https://github.com/mlaraki/cub3D_leaks_maps_tester)

**** Results ****

![GitHub Logo](/extras/images/cub3D_leaks_maps_tester.png)

*I've changed a few "Invalid Maps" from the tester accordingly to what I interpreted from the .pdf as correct or wrong.*


https://github.com/l-yohai/cub3d/tree/master/mlx_example

https://lodev.org/cgtutor/raycasting.html

https://github.com/taelee42/mlx_example




gcc -Wall -Wextra -Werror -fsanitize=address cub3d.c ./sources/utils/*.c ./sources/map/map.c ./sources/events/events.c ./sources/get_next_line/*.c ./sources/libft/*.c ./sources/file_parsing/*.c ./sources/file_parsing/elements_parsing/*.c ./sources/file_parsing/map_parsing/*.c ./sources/textures/textures.c  ./sources/events/raycasting/*.c ./sources/events/keys/keys_1.c ./sources/events/keys/keys_2.c -lbsd -lmlx -lXext -lX11 -lm

gcc -fsanitize=address cub3d.c ./sources/utils/*.c ./sources/events/events.c ./sources/map/map.c ./sources/get_next_line/*.c ./sources/libft/*.c ./sources/file_parsing/*.c ./sources/file_parsing/elements_parsing/*.c ./sources/file_parsing/map_parsing/*.c ./sources/textures/textures.c  ./sources/events/raycasting/*.c ./sources/events/keys/keys_1.c ./sources/events/keys/keys_2.c  -lbsd -lmlx -lXext -lX11 -lm

gcc cub3d.c ./sources/utils/*.c ./sources/events/events.c ./sources/get_next_line/*.c  ./sources/map/map.c ./sources/libft/*.c ./sources/file_parsing/*.c ./sources/file_parsing/elements_parsing/*.c ./sources/file_parsing/map_parsing/*.c ./sources/textures/textures.c ./sources/events/raycasting/*.c ./sources/events/keys/keys_1.c ./sources/events/keys/keys_2.c -lbsd -lmlx -lXext -lX11 -lm

gcc -I  /usr/local/lib -lmlx -framework OpenGL -framework AppKit  main.c error.c events.c images.c map.c raycasting.c textures.c

gcc -lmlx -framework AppKit main.c error.c events.c images.c map.c raycasting.c textures.c

gcc -lmlx -framework OpenGL -framework AppKit main.c error.c events.c images.c map.c raycasting.c textures.c


Cenas para alterar e verificar no Mac:

Mudar o hook 33 (Destroy Window) para 17. Porque no Linux é 33.
Meter os a Cruz com as cenas do Mac.

Ver o limite da window do Mac e alterar conforme.

Correr isto sem o -fsanitize=address no live. -fsanitize=address buga isto e crasha.

Não estás a usar os keys.h. Apaguei. Possívelmente vou precisar.
