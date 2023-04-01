#include "push_swap.h"

int	check_err(int argN, char **args)
{
	int	i;
	int	j;

	i = 1;
	if (argN == 1)
	{
		printf("Error\n");
		return (0);
	}
	while (i < argN)
	{
		j = 0;
		while (args[i][j])
		{
			if (!(args[i][j] >= '0' && args[i][j] <= '9'))
			{
				printf("Error\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (i - 1);
}
