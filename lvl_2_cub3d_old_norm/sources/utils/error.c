/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 21:48:32 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/15 15:29:46 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int		error_message4(int message)
{
	if (message == 31)
		write(1, "Error\nMap has empty lines.\n", 28);
	else if (message == 32)
		write(1, "Error\nMap has a value that isn't (0,1,2,N,E,S,W).\n", 51);
	else if (message == 33)
		write(1, "Error\nMap doesn't have a player start.\n", 40);
	else if (message == 34)
		write(1, "Error\nMap has more than one player start.\n", 43);
	else if (message == 35)
		write(1, "Error\nMap too small.\n", 22);
	else if (message == 36)
		write(1, "Error\nMap not enclosed.\n", 25);
	else if (message == 37)
		write(1, "Error\nTexture Path not found or valid.\n", 40);
	else if (message == 38)
		write(1, "Error\nRepeated element.\n", 25);
	else if (message == 39)
		write(1, "Error\nProblem in elements.\n", 28);
	else if (message == 40)
		write(1, "Error\nArguments are Invalid.\n", 30);
	return (0);
}

static int		error_message3(int message)
{
	if (message == 23)
		write(1, "Error\nElement F is not well formatted in wrong order\n", 54);
	else if (message == 24)
		write(1, "Error\nInvalid RGB after F element.\n", 36);
	else if (message == 25)
		write(1, "Error\nInvalid RGB on F. Should be between 0 and 255.\n", 54);
	else if (message == 26)
		write(1, "Error\nWrong number of parameters on C element.\n", 48);
	else if (message == 27)
		write(1, "Error\nElement C is not well formatted or wrong order\n", 54);
	else if (message == 28)
		write(1, "Error\nInvalid RGB after C element.\n", 36);
	else if (message == 29)
		write(1, "Error\nInvalid RGB on C. Should be between 0 and 255.\n", 54);
	else if (message == 30)
		write(1, "Error\nIncomplete file.\n", 24);
	return (error_message4(message));
}

static int		error_message2(int message)
{
	if (message == 11)
		write(1, "Error\nElement SO is not well formated or wrong order\n", 54);
	else if (message == 12)
		write(1, "Error\nInvalid file extension after SO element.\n", 48);
	else if (message == 13)
		write(1, "Error\nWrong number of parameters on WE element.\n", 49);
	else if (message == 14)
		write(1, "Error\nElement WE is not well formated or wrong order\n", 54);
	else if (message == 15)
		write(1, "Error\nInvalid file extension after WE element.\n", 48);
	else if (message == 16)
		write(1, "Error\nWrong number of parameters on EA element.\n", 49);
	else if (message == 17)
		write(1, "Error\nElement EA is not well formated or wrong order\n", 54);
	else if (message == 18)
		write(1, "Error\nInvalid file extension after EA element.\n", 48);
	else if (message == 19)
		write(1, "Error\nWrong number of parameters on S element.\n", 48);
	else if (message == 20)
		write(1, "Error\nElement S is not well formatted or wrong order\n", 54);
	else if (message == 21)
		write(1, "Error\nInvalid file extension after S element.\n", 47);
	else if (message == 22)
		write(1, "Error\nWrong number of parameters on F element.\n", 48);
	return (error_message3(message));
}

int				error_message(int message)
{
	if (message == 0)
		write(1, "Error\nWrong number of arguments.\n", 34);
	else if (message == 1)
		write(1, "Error\nInvalid file extension.\n", 31);
	else if (message == 2)
		write(1, "Error\nInvalid file name.\n", 26);
	else if (message == 3)
		write(1, "Error\nInvalid file.\n", 21);
	else if (message == 4)
		write(1, "Error\nWrong number of parameters on R element.\n", 48);
	else if (message == 5)
		write(1, "Error\nElement R is not well formatted or wrong order\n", 54);
	else if (message == 6)
		write(1, "Error\nInvalid Width or Height after R element.\n", 48);
	else if (message == 7)
		write(1, "Error\nWrong number of parameters on NO element.\n", 49);
	else if (message == 8)
		write(1, "Error\nElement NO is not well formated or wrong order\n", 54);
	else if (message == 9)
		write(1, "Error\nInvalid file extension after NO element.\n", 48);
	else if (message == 10)
		write(1, "Error\nWrong number of parameters on SO element.\n", 49);
	return (error_message2(message));
}
