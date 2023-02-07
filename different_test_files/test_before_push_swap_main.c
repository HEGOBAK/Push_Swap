#include "push_swap.h"

#include <stdio.h>

void    printlist(t_list *list)
{
    while (list)
    {
        printf ("Value : %d", list->value);
        printf ("  Index : %d\n", list->index);
        list = list->next;
    }
}

int	main(int ac, char **av)
{
	t_list	*list_a;
	int		list_size;

	if (ac < 2)
		return (0);
    printf("\n--first stage passed-- \n");
	if (!check_input(av))
		free_and_exit(NULL, NULL);
    printf("\n--second stage passed-- \n");
	list_a = insert_input(ac, av);
    printf("\n--third stage passed-- \n");
    printlist(list_a);
	list_size = get_list_size(list_a);
    printf("\n--forth stage passed-- \n");
    printf ("List_size : %d\n", list_size);
	assign_indexes(list_a);
    printf("\n--sixth stage passed-- \n");
    printlist(list_a);
    return (0);
}