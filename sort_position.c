/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:10:49 by jchu              #+#    #+#             */
/*   Updated: 2023/02/11 18:09:33 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_position(t_list *list)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = list;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
		//printlist(list);
	}
}

int	get_lowest_index_position(t_list *list)
{
	int	ret;
	int	l_pos;

	assign_position(list);
	l_pos = list->index;
	while (list)
	{
		//printf (" TEST \n");
		if (list->index <= l_pos)
		{
			//printf (" IN \n");
			l_pos = list->index;
			ret = list->position;
			//printf (" list index : %d ", list->index);
			//printf (" index position : %d ", list->position);
		}
		list = list->next;
	}
	return (ret);
}

int	get_target(t_list *a, int b_index)
{
	int		t_pos;
	int		t_index;
	t_list	*list_a;

	list_a = a;
	t_index = INT_MAX;
	while (list_a)
	{
		//printf ("%d\n", b_index);
		//printf ("%d\n", list_a->index);
		//printlist(list_a);
		if (list_a->index > b_index && list_a->index < t_index)
		{
			t_index = list_a->index;
			t_pos = list_a->position;
		}
		list_a = list_a->next;
	}
	if (t_index != INT_MAX)
		return (t_pos);
	//printlist(a);
	//printf ("--%d", get_lowest_index_position(a));
	return (get_lowest_index_position(a));
}

void	assign_target_position(t_list *a, t_list *b)
{
	t_list	*tmp;

	tmp = b;
	assign_position(a);
	assign_position(b);
	while (tmp)
	{
		tmp->t_position = get_target(a, tmp->index);
		//printlist(b);
		tmp = tmp->next;
	}
}
