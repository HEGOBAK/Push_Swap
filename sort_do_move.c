/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_do_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:10:49 by jchu              #+#    #+#             */
/*   Updated: 2023/02/10 17:41:47 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotate_a(t_list **list, int cost)
{
	while (cost != 0)
	{
		if (cost > 0)
		{
			rotate_a(list);
			cost--;
		}
		else
		{
			reverse_rotate_a(list);
			cost++;
		}
	}
}

void	do_rotate_b(t_list **list, int cost)
{
	while (cost != 0)
	{
		if (cost > 0)
		{
			rotate_b(list);
			cost--;
		}
		else
		{
			reverse_rotate_b(list);
			cost++;
		}
	}
}

void	move(t_list **a, t_list **b, t_list *node)
{
	if (node->cost_a > 0 && node->cost_b > 0)
	{
		while (node->cost_a > 0 && node->cost_b > 0)
		{
			rotate_both(a, b);
			(node->cost_a)--;
			(node->cost_b)--;
		}
	}
	else if (node->cost_a < 0 && node->cost_b < 0)
	{
		while (node->cost_a < 0 && node->cost_b < 0)
		{
			reverse_rotate_both(a, b);
			(node->cost_a)++;
			(node->cost_b)++;
		}
	}
	do_rotate_a(a, node->cost_a);
	do_rotate_b(b, node->cost_b);
	push_b_to_a(a, b);
}

void	do_move(t_list **a, t_list **b)
{
	int		cheapest;
	t_list	*tmp;
	t_list	*ret;

	tmp = *b;
	cheapest = INT_MAX;
	ret = tmp;
	while (tmp)
	{
		if (total_cost(tmp->cost_a, tmp->cost_b) < cheapest)
		{
			cheapest = total_cost(tmp->cost_a, tmp->cost_b);
			ret = tmp;
		}
		tmp = tmp->next;
	}
	move(a, b, ret);
}
