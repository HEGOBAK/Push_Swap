/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:10:49 by jchu              #+#    #+#             */
/*   Updated: 2023/02/11 18:09:36 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_stage(t_list **a, t_list **b, int list_size)
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
	three_digits_sort(a);
}

void	middle_stage(t_list **a, t_list **b)
{
	while (*b)
	{
		assign_target_position(*a, *b);
		assign_cost(*a, *b);
		do_move(a, b);
	}
}

void	final_stage(t_list **a, int list_size)
{
	int		l_pos;

	l_pos = get_lowest_index_position(*a);
	//printf ("%d\n", l_pos);
	if (is_list_sorted(*a))
		return ;
	else
	{
		if (l_pos < list_size / 2)
		{
			while (l_pos != 0)
			{
				rotate_a(a);
				l_pos--;
			}
		}
		else
		{
			while (l_pos < list_size)
			{
				reverse_rotate_a(a);
				l_pos++;
			}
		}
	}
}

void	sort(t_list **a, t_list **b, int list_size)
{
	first_stage(a, b, list_size);
	middle_stage(a, b);
	//printlist(*a);
	final_stage(a, get_list_size(*a));
	//printlist(*a);
}
