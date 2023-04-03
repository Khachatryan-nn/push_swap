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

void	swap(t_list **start)
{
	void	*temp;

	temp = (void *)malloc(sizeof(int));
	if (!temp)
		return ;
	if (ft_lstsize(*start) > 1)
	{
		temp = (*start)->content;
		(*start)->content = (*start)->next->content;
		(*start)->next->content = temp;
	}
	return ;
}

void	pushb(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!a || !*a)
		return ;
	temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return ;
	ft_lstadd_front(b, ft_lstnew((*a)->content));
	temp = (*a);
	*a = (*a)->next;
	ft_lstdelone(temp, free);
	(*a)->prev = 0;
	return ;
}
