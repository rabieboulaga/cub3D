/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@students.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:55:00 by rboulaga          #+#    #+#             */
/*   Updated: 2025/04/17 19:10:14 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	walls(t_data *data, t_map *map)
{
	int i;

	i = 0;
	while(data->content[i])
	{
		printf("%s\n", data->content[i]);
		if(ft_strlen(data->content[i]) > 1)
		{

			if(data->content[i][ft_strlen(data->content[i]) - 1] == '0')
			{
				free_map(map);
				free(data->content);
				my_exit(data, "Invalid map: map must be enclosed by walls\n");
			}
		}
			i++;
	}
}

void	map_parsing(t_data *data, t_map *map)
{
	walls(data, map);



}
