/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_extraction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabia <rabia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:19:45 by rboulaga          #+#    #+#             */
/*   Updated: 2025/02/24 18:56:57 by rabia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	skip_empty_lines(char **str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(str[i])
	{
		if (ft_strlen(str[i]) == 1 && str[i][0] == '\n')
			j++;
		
	}
}

int	remove_newline(char **str)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	len = 0;
	while (str && str[len])
		len++;
	while (str && str[j])
	{
		if (len - 1 == j)
			break ;
		i = ft_strlen(str[j]);
		if (i > 1)
			str[j][i - 1] = '\0';
		j++;
	}
	return (len);
}

void	data_extraction(char *file, t_data *data)
{
    int i;

    i = 0;
	data->fd = open(file, O_RDONLY);
	printf("the len = %d\n", data->len);
    data->map = malloc(sizeof(char *) * data->len);
	data->map[i] = get_next_line(data->fd);
	while (data->map[i])
	{
		i++;
		data->map[i] = get_next_line(data->fd);
	}
	close(data->fd);
	
	// remove_newline(data->map);
}
