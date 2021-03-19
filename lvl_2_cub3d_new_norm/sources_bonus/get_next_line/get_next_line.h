/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:37:41 by marvin            #+#    #+#             */
/*   Updated: 2021/03/19 15:02:20 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# ifndef ARRAY_MAX_SIZE
#  define ARRAY_MAX_SIZE 4096
# endif

typedef struct s_struct
{
	int		i;
	int		a;
	char	*temp;
	int		ret;
	int		return_number;
	char	*buffer;
}				t_struct;

int				get_next_line(int fd, char **line);
char			*ft_strjoinn(char *s1, char const *s2);
char			*ft_strdupp(const char *s);
size_t			ft_strlenn(const char *s);
char			*ft_strchrr(const char *str, int c);

#endif
