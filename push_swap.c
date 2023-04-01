#include "push_swap.h"

void print_list(t_list *start)
{
    t_list *ptr;
    int *iptr;

    if (start == NULL)
    {
        ft_printf("Error: linked list is empty.\n");
        return;
    }
    ptr = start;
    while (ptr != NULL)
    {
        if (ptr->content == NULL)
        {
            ft_printf("Error: content pointer is NULL.\n");
            ptr = ptr->next;
            continue;
        }
        iptr = (int *)ptr->content;
        if ((uintptr_t)iptr % sizeof(int) != 0)
        {
            ft_printf("Error: content pointer is not aligned for int.\n");
            ptr = ptr->next;
            continue;
        }
        ft_printf("%d\n", *iptr);
        ptr = ptr->next;
    }
}

int	main(int argv, char **argc)
{
	t_list	*a;
	//t_list	*b;
	int		len;


	len = check_err(argv, argc);
	if (!len)
		return (0);
	a = (t_list *)malloc(sizeof(t_list) * len);
	//b = (arg_list *)malloc(sizeof(arg_list) * len);
	a = fill_a(argc, len);
	print_list(a);

    ft_lstclear(&a, free);
}
