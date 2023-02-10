/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:10:49 by jchu              #+#    #+#             */
/*   Updated: 2023/02/10 17:39:46 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stage_1(t_list **a, t_list **b, int list_size)
{
	int	count;
	int	pushed;

	count = 0;
	pushed = 0;
	while (count < list_size && pushed < list_size / 2 && list_size > 3)
	{
		if ((*a)->index <= list_size / 2)
		{
			push_a_to_b(a, b);
			pushed++;
		}
		else
			rotate_a(a);
		count++;
	}
}

void	assign_position(t_list *list)
{
	int		i;

	i = 0;
	while (!list)
	{
		list->position = i++;
		list = list->next;
	}
}

int	get_target(t_list *a, int b_index)
{
	int		ret;
	int		tmp_idx;
	t_list	*list;

	list = a;
	tmp_idx = INT_MIN;
	while (a)
	{
		if (a->index > b_index && a->index < tmp_idx)
		{
			tmp_idx = a->index;
			ret = a->position;
		}
		a = a->next;
	}
	if (tmp_idx != INT_MIN)
		return (ret);
	return ((get_list_bottom(list))->position);
}

void	assign_target_position(t_list *a, t_list *b)
{
	assign_position(a);
	assign_position(b);
	while (b)
	{
		b->t_position = get_target(a, b->index);
		b = b->next;
	}
}

void	sort(t_list **a, t_list **b, int list_size)
{
	stage_1(a, b, list_size);
	three_digits_sort(a);
	while (*b)
	{
		assign_target_position(*a, *b);
		assign_cost(*a, *b);
		do_move(a, b);
	}
}
