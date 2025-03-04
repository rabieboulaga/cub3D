/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabia <rabia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:28:46 by rboulaga          #+#    #+#             */
/*   Updated: 2025/03/01 17:52:27 by rabia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


t_map	*map_lstlast(t_map *lst)
{
	if (!lst)
		return (NULL);
	while ( lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	map_add_front(t_map **lst, t_map *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	map_add_back(t_map **lst, t_map *new)
{
	t_map	*head;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		head = map_lstlast(*lst);
		head->next = new;
	}
}
