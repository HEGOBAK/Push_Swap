/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_digits_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:25:40 by jchu              #+#    #+#             */
/*   Updated: 2023/02/02 21:50:37 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_highest_index(t_list *list)
{
	int	index;

	index = list->index;
	while (list)
	{
		if (list->index > index)
			index = list->index;
		list = list->next;
	}
	return (index);
}

void	three_digits_sort(t_list **list)
{
	int	highest_index;

	highest_index = find_highest_index(*list);
	if (is_list_sorted(*list))
		return ;
	if ((*list)->index == highest_index)
		rotate_a(list);
	else if ((*list)->next->index == highest_index)
		reverse_rotate_a(list);
	if ((*list)->index > (*list)->next->index)
		swap_top_two_a(list);
}
