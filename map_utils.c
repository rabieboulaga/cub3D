/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@students.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:28:46 by rboulaga          #+#    #+#             */
/*   Updated: 2025/03/01 12:15:27 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


t_map	*map_lstlast(t_map *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
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
