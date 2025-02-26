/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabia <rabia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:39:57 by rboulaga          #+#    #+#             */
/*   Updated: 2025/02/24 13:41:09 by rabia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
#include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
#include <stdio.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000

typedef struct c_data
{
	char **content;
	char **map;
	char *str;
	int	d;
	int fd;
	int len;
	char *file;

}	t_data;

int main(int ac, char **av);
void parsing(int ac, char **av, t_data *data);
char	*get_next_line(int fd);
char	*ft_strjoinn(char *s1, char *s2);
char	*ft_strchrr(char *s, int c);
size_t	ft_strlenn(char *str);
char	*ft_strdupp(char *s);
void	my_exit(t_data *data, char *str);
void	data_extraction(char *file, t_data *data);



# endif
#endif
