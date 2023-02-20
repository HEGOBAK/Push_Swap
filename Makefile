# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 00:57:31 by jchu              #+#    #+#              #
#    Updated: 2023/02/11 17:29:05 by jchu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

AR_NAME		= push_swap.a

SRCS		= check_input_utils.c \
				check_input.c \
				insert_and_assign.c \
				list_operations.c \
				utils.c \
				swap_operations.c \
				push_operations.c \
				rotate_operations.c \
				reverse_rotate_operations.c \
				three_digits_sort.c \
				sort.c \
				sort_cost.c \
				sort_do_move.c \
				sort_position.c \
				main.c \

OBJS		= $(SRCS:%.c=%.o)

CC			= gcc

AR			= ar rc

FLAGS		= -Wall -Werror -Wextra

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	$(AR) $(AR_NAME) $(OBJS)
 
all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
