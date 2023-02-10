/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:10:49 by jchu              #+#    #+#             */
/*   Updated: 2023/02/10 17:25:22 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_cost(int position, int list_size)
{
	if (position > list_size / 2)
		return ((list_size - position) * -1);
	return (position);
}

void	assign_cost(t_list *a, t_list *b)
{
	t_list	*list;

	list = b;
	while (b)
	{
		b->cost_a = get_cost(b->t_position, get_list_size(a));
		b->cost_b = get_cost(b->position, get_list_size(list));
		b = b->next;
	}
}

int	abs_val(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

int	total_cost(int a, int b)
{
	return (abs_val(a) + abs_val(b));
}
