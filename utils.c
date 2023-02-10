/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:05:51 by jchu              #+#    #+#             */
/*   Updated: 2023/02/11 00:42:11 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list **list)
{
	t_list	*tmp;

	if (!list || !(*list))
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
	*list = NULL;
}

void	free_and_exit(t_list **list_a, t_list **list_b)
{
	if (list_a == NULL || *list_a != NULL)
		free_list(list_a);
	if (list_b == NULL || *list_b != NULL)
		free_list(list_b);
	write (2, "Error\n", 6);
	exit(1);
}

int	is_list_sorted(t_list *list)
{
	while (list->next != NULL)
	{
		if (list->value > list->next->value)
			return (0);
		list = list->next;
	}
	return (1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write (1, str++, 1);
}
