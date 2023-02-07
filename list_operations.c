/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:40:45 by jchu              #+#    #+#             */
/*   Updated: 2023/01/31 00:10:56 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_list_bottom(t_list *list)
{
	while (list && list->next != NULL)
		list = list->next;
	return (list);
}

t_list	*new_node(int nb)
{
	t_list	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = nb;
	new->index = 0;
	new->next = NULL;
	return (new);
}

void	add_node_bottom(t_list **list, t_list *new)
{
	t_list	*last_node;

	if (!new)
		return ;
	if (!*list)
	{
		*list = new;
		return ;
	}
	last_node = get_list_bottom(*list);
	last_node->next = new;
}

int	get_list_size(t_list *list)
{
	int	ret;

	ret = 0;
	if (!list)
		return (0);
	while (list != NULL)
	{
		list = list->next;
		ret++;
	}
	return (ret);
}
