#include "push_swap.h"

t_list	*fill_a(char **args, int len)
{
	t_list	*start;
	int		i;
	int		*content;

	i = 0;
	start = NULL;
	while (i < len)
	{
		content = (int *)malloc(sizeof(int));
		if (!content)
		{
			ft_lstclear(&start, free);
			return (NULL);
		}
		*content = ft_atoi(args[i + 1]);
		ft_lstadd_back(&start, ft_lstnew(content));
		i++;
	}
	return (start);
}