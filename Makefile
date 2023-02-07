# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 00:57:31 by jchu              #+#    #+#              #
#    Updated: 2023/02/02 21:45:16 by jchu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap.a

SRCS		= check_input_utils.c \
				check_input.c \insert_and_assign.c \
				list_operations.c \
				utils.c \
				swap_operations.c \
				push_operations.c \
				rotate_operations.c \
				reverse_rotate_operations.c \
				three_digits_sort.c \

OBJS		= $(SRCS:%.c=%.o)

CC			= gcc

AR			= ar rc

FLAGS		= -Wall -Werror -Wextra

$(NAME):
	$(CC) $(FLAGS) -c $(SRCS) -I ./
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean: clean
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME) 

re: fclean all