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
	t_list	*b;
	int		len;
	int		*int_arr;

	len = check_err(argv, argc);
	if (!len)
		return (0);
	int_arr = (int *)malloc(sizeof(len));
	if (!int_arr)
		return (0);
	a = (t_list *)malloc(sizeof(t_list));
	if (!a)
	{
		free (int_arr);
		return (0);
	}
	b = (t_list *)malloc(sizeof(t_list));
	if (!b)
	{
		free(a);
		free(int_arr);
		return (0);
	}
	a = fill_a(argc, len);
	ft_printf("Now we are printing our stack a after filling him:\n");
	print_list(a);
	int_arr = fill_int_arr(a, len);
	ft_printf("Now we are printing out our integers array\n");
	for (int i = 0; i < len; i++)
		ft_printf("%d\n", int_arr[i]);
	swap(&a);
	ft_printf("There are stack a after swaping first 2 elements\n");
	print_list(a);
	pushb(&a, &b);
	pushb(&a, &b);
	ft_printf("And there are stack a, after push b 2x\n");
	print_list(a);
	ft_printf("There are stack b, after push b 2x\n");
	print_list(b);
	ft_lstclear(&a, free);
}
