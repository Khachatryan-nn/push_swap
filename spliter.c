#include "push_swap.h"

static int	count_len(int rows, char **strs)
{
	int	i;
	int	j;
	int	counter;

	i = 1;
	counter = 0;
	while (i < rows)
	{
		j = 0;
		while ((strs[i][j] >= '0' && strs[i][j] <= '9') || strs[i][j] == ' ')
		{
			if (strs[i][j] >= '0' && strs[i][j] <= '9')
				counter++;
			j++;
		}
		if (strs[i][j] != '\0')
		{
			printf ("Error\n");
			return (0);
		}
		i++;
	}
	if (counter == 0 && i > 1)
		printf("Error\n");
	return (counter);
}

char	**spliter(int argv, char **argc)
{
	int		i;
	char	*all_there;
	char	**arr;
	char 	*temp;

	i = 1;
	if (count_len(argv, argc) == 0)
		return (NULL);
	all_there = ft_strdup("");
	while (i < argv)
	{
		temp = ft_strjoin(all_there, argc[i]);
		free(all_there);
		all_there = ft_strjoin(temp, " ");
		free(temp);
		i++;
	}
	arr = ft_split(all_there, ' ');
	return (arr);
}
