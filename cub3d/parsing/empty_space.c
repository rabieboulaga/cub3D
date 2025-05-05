/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@students.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:33:57 by rboulaga          #+#    #+#             */
/*   Updated: 2025/05/05 22:49:03 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	empty_space(t_data *data, t_map *map)
{
	(void)map;
	int i = 0;
	while (data->content[i])
	{
		printf("%s\n",data->content[i]);
		i++;

	}
	exit(0);
}
void	check_map_char(t_data *data, t_map *map, int x, int y)
{
	char c = data->content[y][x];

	if (!ft_strchr("01 NWSE", c))
	{
		free_map(map);
		free(data->content);
		my_exit(data, "Invalid map: Map contains an invalid character\n");
	}
	if (ft_strchr("NWSE", c))
	{
		data->help++;
		take_possitions(data, x, y, c);
	}
	if (c == ' ')
		empty_space(data, map);
}


