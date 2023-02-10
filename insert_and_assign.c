/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_and_assign.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:24:24 by jchu              #+#    #+#             */
/*   Updated: 2023/02/10 16:23:39 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(char *av)
{
	long int	nb;
	int			i;
	int			sign;

	i = 0;
	sign = 1;
	nb = 0;
	if (av[i] == '+')
		i++;
	else if (av[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (is_digit(av[i]))
	{
		nb = (nb * 10) + (av[i] - '0');
		i++;
	}
	return (nb * sign);
}

t_list	*insert_input(int ac, char **av)
{
	t_list		*list_a;
	int			i;
	long int	nb;

	i = 1;
	nb = 0;
	list_a = NULL;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			free_and_exit(&list_a, NULL);
		if (i == 1)
			list_a = new_node((int)nb);
		else
			add_node_bottom(&list_a, new_node((int)nb));
		i++;
	}
	return (list_a);
}

void	assign_indexes(t_list *list)
{
	int		bigger_count;
	t_list	*hold;
	t_list	*tmp;

	hold = list;
	while (list)
	{
		tmp = hold;
		bigger_count = 1;
		while (tmp)
		{
			if (list->value > tmp->value)
				bigger_count++;
			tmp = tmp->next;
		}
		list->index = bigger_count;
		list = list->next;
	}
}
