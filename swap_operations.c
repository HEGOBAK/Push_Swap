/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:17:25 by jchu              #+#    #+#             */
/*   Updated: 2023/02/02 17:41:24 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_two(t_list *list)
{
	int	tmp;

	if (!list || list->next == NULL)
		return ;
	tmp = list->value;
	list->value = list->next->value;
	list->next->value = tmp;
	tmp = list->index;
	list->index = list->next->index;
	list->next->index = tmp;
}

void	swap_top_two_a(t_list **list)
{
	swap_top_two(*list);
	ft_putstr("sa\n");
}

void	swap_top_two_b(t_list **list)
{
	swap_top_two(*list);
	ft_putstr("sb\n");
}

void	swap_top_two_both(t_list **list_a, t_list **list_b)
{
	swap_top_two(*list_a);
	swap_top_two(*list_b);
	ft_putstr("ss\n");
}
