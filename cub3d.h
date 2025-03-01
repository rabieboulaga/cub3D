/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@students.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:39:57 by rboulaga          #+#    #+#             */
/*   Updated: 2025/03/01 10:48:37 by rboulaga         ###   ########.fr       */
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

typedef enum e_token {
    NO,   // north texture
    SO,   // south texture
    WE,   // west texture
    EA,   // east texture
    F,    // floor color
    C,    // ceiling color
    MAPP,  // map data
    EMPTY, // IMPTY LINE
} t_token;

typedef struct c_map
{
	t_token type;
	char *line;
	struct c_map *next;
}	t_map;

typedef struct c_data
{
	char **content;
	char **map1;
	char *str;
	int	d;
	int fd;
	int len;
	char *file;

}	t_data;

int main(int ac, char **av);
void parsing(int ac, char **av, t_data *data, t_map *map);
char	*get_next_line(int fd);
char	*ft_strjoinn(char *s1, char *s2);
char	*ft_strchrr(char *s, int c);
size_t	ft_strlenn(char *str);
char	*ft_strdupp(char *s);
void	my_exit(t_data *data, char *str);
void	data_extraction(char *file, t_data *data, t_map *map);
// void    check_elements(t_data *data);
t_map	*map_lstlast(t_map *lst);
void	map_add_front(t_map **lst, t_map *new);
void	map_add_back(t_map **lst, t_map *new);



# endif
#endif
