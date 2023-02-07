/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:17:20 by jchu              #+#    #+#             */
/*   Updated: 2023/02/02 21:41:20 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **src, t_list **dest)
{
	t_list	*temp;

	if (*src == NULL)
		return ;
	temp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = temp;
}

void	push_b_to_a(t_list **list_a, t_list **list_b)
{
	push(list_b, list_a);
	ft_putstr("pa\n");
}

void	push_a_to_b(t_list **list_a, t_list **list_b)
{
	push(list_a, list_b);
	ft_putstr("pb\n");
}
