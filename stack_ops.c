#include "push_swap.h"

t_list	*fill_a(char **args, int len)
{
	t_list	*start;
	int		i;
	int		*content;

	i = 1;
	content = (int *)malloc(sizeof(int));
	start = (t_list *)malloc(sizeof(t_list));
	if (!start)
		return (NULL);
	while (i <= len)
	{
		*content = ft_atoi(args[i]);
		ft_lstadd_back(&start, ft_lstnew(content));
		i++;
	}
	return (start);
}