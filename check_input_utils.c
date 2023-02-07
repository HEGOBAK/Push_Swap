/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:13:42 by jchu              #+#    #+#             */
/*   Updated: 2023/02/01 22:38:23 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	arg_is_zero(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' && arg[i] == '+')
		i++;
	while (arg[i] && arg[i] == '0')
		i++;
	if (arg[i] == '\0')
		return (1);
	return (0);
}

int	check_same_num(char *av1, char *av2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (av1[i] == '-')
	{
		if (av2[j] != '-')
			return (0);
	}
	else if (av2[j] == '-')
		return (0);
	if (av1[i] == '+')
		i++;
	else if (av2[j] == '+')
		j++;
	while (av1[i] || av2[j])
	{
		if (av1[i] - av2[j] != 0)
			return (0);
		i++;
		j++;
	}
	return (1);
}
