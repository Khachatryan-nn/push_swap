#include "../includes/push_swap.h"

void print_list(t_list *start)
{
    t_list *ptr;
    if (start == NULL)
    {
        ft_printf("Error: linked list is empty.\n");
        return;
    }
    ptr = start;
    while (ptr != NULL)
    {
        if (!(ptr->data))
        {
            ft_printf("Error: data is NULL.\n");
            ptr = ptr->next;
            continue;
        }
        ft_printf("%d\n", (ptr->data));
        ptr = ptr->next;
    }
}

int	main(int argv, char **argc)
{
	t_list	*a;
	t_list	*b;
	char	**arr;
	int		*int_arr;
	int		len;

	len = 0;
	arr = spliter(argv, argc);
	if (!arr)
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
	a = fill_a(arr);
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
	pushb(&a, &b);
	ft_printf("And there are stack a, after push b 3x\n");
	print_list(a);
	ft_printf("There are stack b, after push b 3x\n");
	print_list(b);
	ft_lstclear(&a);
}
