/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:17:28 by jchu              #+#    #+#             */
/*   Updated: 2023/02/02 21:46:21 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **list)
{
	t_list	*last;
	t_list	*second_last;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	second_last = *list;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *list;
	*list = last;
}

void	reverse_rotate_a(t_list **list)
{
	reverse_rotate(list);
	ft_putstr("rra\n");
}

void	reverse_rotate_b(t_list **list)
{
	reverse_rotate(list);
	ft_putstr("rrb\n");
}

void	reverse_rotate_both(t_list **list_a, t_list **list_b)
{
	reverse_rotate(list_a);
	reverse_rotate(list_b);
	ft_putstr("rrr\n");
}
