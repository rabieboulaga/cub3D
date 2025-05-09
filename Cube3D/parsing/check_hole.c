/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hole.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@students.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:43:49 by rboulaga          #+#    #+#             */
/*   Updated: 2025/05/09 03:57:36 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_player(char c)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
		return 1;
	else
		return 0;
}

void 	hole_error(t_data *data, t_map *map)
{
	free_map(map);
	free(data->content);
	my_exit(data, "Invalid map");
}
void		calcul(char *str, int j)
{
	int len;

	len = ft_strlen(str);
	printf("len of the next line=== %d\n,", len);
	printf("len of the current line=== %d\n,", j);

}
int	valide_line(t_data *data, int i, int j)
{
	int len;

	len = ft_strlen(data->content[i]);
	// printf("%s\n", data->content[i]);
	// printf("len of line = %d\n", len);
	// printf("current position = %d\n", j);
	if (j > i)
		return 1;
	return 0;
}


void searx(int i, int j, t_data *data, t_map *map)
{
	if	(is_space(data->content[i][j + 1]))
		hole_error(data, map);
	else if (is_space(data->content[i][j - 1]))
		hole_error(data, map);


	else if (valide_line(data, i + 1, j))
		hole_error(data, map);


	else if (valide_line(data, i - 1, j))
			hole_error(data, map);

	// calcul(data->content[i + 1], j);
}

void	check_hole(t_data *data, t_map *map)
{
	int i;
	int j;

	i = 0;
	while(data->content[i])
	{
		j = 0;
		while(data->content[i][j])
		{
			if (data->content[i][j] == '0')
				searx(i, j, data, map);
			else if(check_player(data->content[i][j]))
				searx(i, j, data, map);
			j++;
		}
		i++;
	}
}

















































// void    ft_is_map_valid(t_data *ret)
// {
//     int    i;
//     int    j;

//     i = 0;
//     j = 0;
//     while (ret->maps[i])
//     {
//         while (ret->maps[i][j] != '\0')
//         {
//             if (ret->maps[i][j] == '0')
//                 ft_check_space(ret, i, j);
//             else if (is_a_player(ret->maps[i][j]) == true)
//                 ft_check_space(ret, i, j);
//             j++;!data->content[i + 1][j]
//         }
//         j = 0;
//         i++;
//     }
// }
// void    ft_check_space(t_data *ret, int i, int j)
// {
//     int    total;
//     int    len;

//     total = 0;
//     len = 0;

//     len = strlen(ret->maps[i]);
//     if ( ret->maps[i][j + 1] == ' ')   // limn
//         ft_free_printf(ret, "invalid map");



//     else if ( ret->maps[i][j - 1] == ' ')  // lissr
//         ft_free_printf(ret, "invalid map");


//     else if (ft_line_valid(ret->maps[i + 1], j) == true    // lta7t
//         && ft_isspace_new(ret->maps[i + 1][j]))
//         ft_free_printf(ret, "invalid map");


//     else if (ft_line_valid(ret->maps[i - 1], j) == true   // lfo0
//         && ft_isspace_new(ret->maps[i - 1][j]))
//         ft_free_printf(ret, "invalid map");



//     else if (ft_line_valid(ret->maps[i + 1], j) == false
//         || ft_line_valid(ret->maps[i - 1], j) == false)
//         ft_free_printf(ret, "invalid map");
// }
