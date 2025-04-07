/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabia <rabia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:51:37 by rabia             #+#    #+#             */
/*   Updated: 2025/04/06 10:03:05 by rabia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    Invalid_element(t_data *data, t_map *map, t_map *tmp)
{
    while(map->next && map->type == MAPP)
        map = map->next;
    if (map == NULL)    
        return ;
    if(map->type == EMPTY)
    {
        
        while(map->type == EMPTY && map->next)
        map = map->next;
        if (map == NULL)    
        return ;
        printf("%s", map->line);
    }
    free_map(tmp);
	my_exit(data, "Invalid element in configuration file\n");
}

void    take_map(t_data *data, t_map *map)
{
    t_map *tmp;

    while(map->next && map->type != MAPP)
        map = map->next;
    tmp = map;
    Invalid_element(data, map, tmp);
    // while(map->next)
    // {
    //     if(map->type)
        
    // }
    // //you should check if the there is empty line inside of mapp or some wrong characters
}

//
// if (map->type != MAPP && map->type != EMPTY)
// {
//     free(map);
//     my_exit(data, "Invalid element in configuration file\n"); 
// }
// if (map->type == EMPTY)
// {
//     while(map->type == EMPTY && map->next)
    
// }