/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_extraction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabia <rabia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:19:45 by rboulaga          #+#    #+#             */
/*   Updated: 2025/03/03 04:32:44 by rabia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	skip_empty_lines(char **str)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while(str[i])
// 	{
// 		if (ft_strlen(str[i]) == 1 && str[i][0] == '\n')
// 			j++;

// 	}
// }

void	type_definition(t_map *map, char *line)
{
	int i;

	i = 0;
	if(ft_strncmp)
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

	while (map->next)
	{
		printf("%s\n", map->line);
		map = map->next;
	}
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