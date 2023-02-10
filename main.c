/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:54:13 by jchu              #+#    #+#             */
/*   Updated: 2023/02/11 04:43:20 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(t_list *list)
{
	while (list)
	{
		printf ("Value : %d", list->value);
		printf ("  Index : %d", list->index);
		printf ("  Position : %d", list->position);
		printf ("  T_Positioin : %d", list->t_position);
		printf ("  Cost A : %d", list->cost_a);
		printf ("  Cost B : %d\n", list->cost_b);
		list = list->next;
	}
	printf ("\n--------------------\n");
}

void	push_swap(t_list **list_a, t_list **list_b, int list_size)
{
	if (list_size == 2 && !is_list_sorted(*list_a))
		swap_top_two_a(list_a);
	if (list_size == 3)
		three_digits_sort(list_a);
	if (list_size > 3 && !is_list_sorted(*list_a))
		sort(list_a, list_b, list_size);
}

int	main(int ac, char **av)
{
	t_list	*list_a;
	t_list	*list_b;
	int		list_size;

	if (ac < 2)
		return (0);
	if (!check_input(av))
		free_and_exit(NULL, NULL);
	list_a = insert_input(ac, av);
	list_b = NULL;
	list_size = get_list_size(list_a);
	assign_indexes(list_a);
	//printlist(list_a);                             //BEFORE SORTING
	push_swap(&list_a, &list_b, list_size);
	//printlist(list_a);						     //AFTER SORTING
	//printlist(list_b);
	free_list(&list_a);
	free_list(&list_b);
	return (0);
}
