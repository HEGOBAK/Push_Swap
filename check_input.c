/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:13:42 by jchu              #+#    #+#             */
/*   Updated: 2023/02/02 21:48:01 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_is_number(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] != '\0')
		i++;
	while (str[i] && is_digit(str[i]))
		i++;
	if (str[i] != '\0' && !is_digit(str[i]))
		return (0);
	return (1);
}

int	have_same_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (check_same_num(av[i], av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_input(char **av)
{
	int	zero_count;
	int	i;

	zero_count = 0;
	i = 1;
	while (av[i])
	{
		if (!arg_is_number(av[i]))
			return (0);
		zero_count += arg_is_zero(av[i]);
		i++;
	}
	if (zero_count > 1 || have_same_args(av))
		return (0);
	return (1);
}
