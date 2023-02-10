/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:10:49 by jchu              #+#    #+#             */
/*   Updated: 2023/02/11 05:19:56 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stage_1(t_list **a, t_list **b, int list_size)
{
	int	count;
	int	pushed;

	count = 0;
	pushed = 0;
	while (count < list_size && pushed < list_size / 2 && list_size > 6)
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
	while (list_size - pushed > 3)
	{
		push_a_to_b(a, b);
		pushed++;
	}
}

void	sort(t_list **a, t_list **b, int list_size)
{
	stage_1(a, b, list_size);
	three_digits_sort(a);
	while (*b)
	{
		assign_target_position(*a, *b);
		assign_cost(a, b);
		do_move(a, b);
	}
}
