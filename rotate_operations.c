/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:17:27 by jchu              #+#    #+#             */
/*   Updated: 2023/02/02 21:46:32 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **list)
{
	t_list	*temp;
	t_list	*bottom;

	temp = *list;
	*list = (*list)->next;
	bottom = get_list_bottom(*list);
	temp->next = NULL;
	bottom->next = temp;
}

void	rotate_a(t_list **list)
{
	rotate(list);
	ft_putstr("ra\n");
}

void	rotate_b(t_list **list)
{
	rotate(list);
	ft_putstr("rb\n");
}

void	rotate_both(t_list **list_a, t_list **list_b)
{
	rotate(list_a);
	rotate(list_b);
	ft_putstr("rr\n");
}
