/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:54:52 by jchu              #+#    #+#             */
/*   Updated: 2023/02/11 17:20:35 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct node
{
	int			value;
	int			index;
	int			position;
	int			t_position;
	int			cost_a;
	int			cost_b;
	struct node	*next;
}	t_list;

void		printlist(t_list *list);

/* Utils */
void		free_and_exit(t_list **list_a, t_list **list_b);
void		free_list(t_list **list);
int			is_list_sorted(t_list *list);
void		ft_putstr(char *str);

/* List Operations */
t_list		*get_list_bottom(t_list *list);
t_list		*new_node(int nb);
void		add_node_bottom(t_list **list, t_list *new);
int			get_list_size(t_list *list);

/* Check Inputs */
int			arg_is_number(char *str);
int			have_same_args(char **av);
int			check_input(char **av);

/* Check Inputs Utils */
int			is_digit(char c);
int			arg_is_zero(char *arg);
int			check_same_num(char *av1, char *av2);

/* Insert & Assign */
long int	ft_atoi(char *av);
t_list		*insert_input(int ac, char **av);
void		assign_indexes(t_list *list);

/* Swap Operations */
void		swap_top_two(t_list *list);
void		swap_top_two_a(t_list **list);
void		swap_top_two_b(t_list **list);
void		swap_top_two_both(t_list **list_a, t_list **list_b);

/* Push Operations */
void		push(t_list **src, t_list **dest);
void		push_b_to_a(t_list **list_a, t_list **list_b);
void		push_a_to_b(t_list **list_a, t_list **list_b);

/* Rotate Operations */
void		rotate(t_list **list);
void		rotate_a(t_list **list);
void		rotate_b(t_list **list);
void		rotate_both(t_list **list_a, t_list **list_b);

/* Reverse Rotate Operations */
void		reverse_rotate(t_list **list);
void		reverse_rotate_a(t_list **list);
void		reverse_rotate_b(t_list **list);
void		reverse_rotate_both(t_list **list_a, t_list **list_b);

/* Three Digits Sort */
int			find_highest_index(t_list *list);
void		three_digits_sort(t_list **list);

/* Sort */
void		first_stage(t_list **a, t_list **b, int list_size);
void		middle_stage(t_list **a, t_list **b);
void		last_stage(t_list **a);
void		sort(t_list **a, t_list **b, int list_sisze);

/* Sort Position */
void		assign_position(t_list *list);
int			get_lowest_index_position(t_list *list);
int			get_target(t_list *a, int b_index);
void		assign_target_position(t_list *a, t_list *b);

/* Sort Cost */
int			get_cost(int position, int list_size);
void		assign_cost(t_list *a, t_list *b);
int			abs_val(int nb);
int			total_cost(int a, int b);

/* Sort Do Move */
void		do_rotate_a(t_list **list, int cost);
void		do_rotate_b(t_list **a, int cost);
void		move(t_list **a, t_list **b, t_list *node);
void		do_move(t_list **a, t_list **b);

#endif