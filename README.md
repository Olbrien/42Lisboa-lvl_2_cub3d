# cub3d

###### <i>Recent Update on 16/03/2021.</i>
Done everything I could. Waiting for upload.

###### <i>Old Update on 15/03/2021.</i>
Done with old Norminette.

###### <i>Old Update on 13/03/2021.</i>
Done with Norminette v3.

**** Pictures ****

![GitHub Logo](/extras/images/picture_1.png)\
![GitHub Logo](/extras/images/picture_2.png)

**** Testers ****

[cub3D_leaks_maps_tester](https://github.com/mlaraki/cub3D_leaks_maps_tester)

**** Results ****

![GitHub Logo](/extras/images/cub3D_leaks_maps_tester.png)

*I've changed a few "Invalid Maps" from the tester accordingly to what I interpreted from the .pdf as correct or wrong.*


**** Info ****

To run my project on Mac simply type "Make" or "Make re" to compile and run one of each map that isn't _bonus.cub \
To run my project on Linux simply type "Make linux" to compile and run one of each map that isn't _bonus.cub \
`./cub3D ./maps/test.cub` \
`./cub3D ./maps/test2.cub` 

To run the Bonus project, on Mac type "Make bonus", on Linux type "Make linux_bonus" and run the map that ends with _bonus.cub \
`./cub3D ./maps/test_bonus.cub` 

These links helped me with the project.

https://harm-smits.github.io/42docs/libs/minilibx

https://lodev.org/cgtutor/raycasting.html \
https://github.com/l-yohai/cub3d/tree/master/mlx_example

My advice for people starting this project, learn the minilibx using the first link. You don't need to master it, just learn the basics. Know that Linux and Mac are different machines, they have different ways of making the same thing working. For instance, closing a window using the X on Mac the code is 17, on Linux is 33. 

After learning minilibx first thing you should do is the file parsing. This part it's the part that I've enjoyed the most. The map parsing has many ways of doing it. If you want to try for yourself, don't read how I did it. If you encounter any problem, then if you want go ahead.

I started to parse the map to a two dimensions string. I parsed the tabs as spaces (1 tab = 4 spaces).

<pre>
      1111111111111111111111111
      1000000000000000000000001
      100000000200000020000W001
      1000000000000000000000001
111111111000000000000000000000001
100000000000111111100000000111111
1000000000001     10000000001
1000000000001     10000200001
1000000000001     10000000001
10000200000011111110000000001
10000000000000000000000000001
1000000111000001110000000000111
10000001 1000001 100000000001
11111111 1111111 111111111111
</pre>

Then, I added a different char on the spaces to identify better the surroundings.

<pre>
###################################
#######1111111111111111111111111###
#######1000000000000000000000001###
#######100000000200000020000W001###
#######1000000000000000000000001###
#1111111000000000000000000000001###
#100000000000111111100000000111111#
#1000000000001#####10000000001#####
#1000000000001#####10000200001#####
#1000000000001#####10000000001#####
#10000200000011111110000000001#####
#10000000000000000000000000001#####
#1000000111000001110000000000111###
#10000001#1000001#100000000001#####
#11111111#1111111#111111111111#####
###################################
</pre>

And then I added a border.

<pre>
*************************************
*###################################*
*#######1111111111111111111111111###*
*#######1000000000000000000000001###*
*#######100000000200000020000W001###*
*#######1000000000000000000000001###*
*#1111111000000000000000000000001###*
*#100000000000111111100000000111111#*
*#1000000000001#####10000000001#####*
*#1000000000001#####10000200001#####*
*#1000000000001#####10000000001#####*
*#10000200000011111110000000001#####*
*#10000000000000000000000000001#####*
*#1000000111000001110000000000111###*
*#10000001#1000001#100000000001#####*
*#11111111#1111111#111111111111#####*
*###################################*
************************************
</pre>

After doing this, I could now check if the '#' are surrounded by 1's or *'s, if they are not, it means the map is not enclosed.

Then you should start to do the raycast following the Lodev guide. If you are having trouble following his guide, the link below it has his code translated to C.
