/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_extraction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@students.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:19:45 by rboulaga          #+#    #+#             */
/*   Updated: 2025/03/07 21:35:29 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	my_cmp(char *s1, char *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (*s2 && *s2 == ' ')
		s2++;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}


void	type_definition(t_map *map)
{
	while (map->next)
	{
		if(!my_cmp("NO ", map->line, 3))
			printf(" line = %s : all is good\n", map->line);
		map = map->next;
	}
}

void	get_elements(t_map *map, char *str)
{
	t_map *newnode;

	newnode = (t_map *)malloc(sizeof(t_map));
	newnode->line = ft_strdup(str);
	newnode->next = NULL;
	if (!map)
		map_add_front(&map, newnode);
	map_add_back(&map, newnode);
	(void)str;
}


void	data_extraction(char *file, t_data *data, t_map *map)
{
	char *str;

	data->fd = open(file, O_RDONLY);
	map->line = get_next_line(data->fd);
	str = get_next_line(data->fd);
	while(str)
	{
		free(str);
		str = get_next_line(data->fd);
		get_elements(map, str);
	}
	type_definition(map);

	// while (map->next)
	// {
	// 	printf("%s\n", map->line);
	// 	map = map->next;
	// }
	close(data->fd);
}





// data->map1 = malloc(sizeof(char *) * data->len);
// 	data->map1[i] = get_next_line(data->fd);
// 	while (data->map1[i])
// 	{
	// 		i++;
	// 		data->map1[i] = get_next_line(data->fd);
	// 	}
	// 	data->map1[i] = '\0';


	// int	remove_newline(char **str)
	// {
	// 	int	i;
	// 	int	j;
	// 	int	len;

	// 	j = 0;
	// 	len = 0;
	// 	while (str && str[len])
	// 		len++;
	// 	while (str && str[j])
	// 	{
	// 		if (len - 1 == j)
	// 			break ;
	// 		i = ft_strlen(str[j]);
	// 		if (i > 1)
	// 			str[j][i - 1] = '\0';
	// 		j++;
	// 	}
	// 	return (len);
	// }



// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*str1;
// 	unsigned char	*str2;

// 	str1 = (unsigned char *)s1;
// 	str2 = (unsigned char *)s2;
// 	i = 0;
// 	j = 0;
// 	while (str2[i] && str2[i] == ' ')
// 		i++;
// 	while (i < n && (s1[i + j] != '\0' || s2[i + j] != '\0'))
// 	{
// 		if (str1[i + j] != str2[i + j])
// 			return (str1[i + j] - str2[i + j]);
// 		i++;
// 	}
// 	return (0);
// }
