/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:47:39 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/26 15:49:49 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*Counts number of numbers in our strings, but if there any other character
*beside numbers and spaces, it return's 0 and outputs Error message
*/
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
		while (ft_isdigit(strs[i][j]) || strs[i][j] == ' ' || \
			(strs[i][j] == '-' && ft_isdigit(strs[i][j + 1])))
		{
			if (strs[i][j] >= '0' && strs[i][j] <= '9')
				counter++;
			j++;
		}
		if (strs[i][j] != '\0')
			return (0 && ft_printf ("Error\n"));
		i++;
	}
	if (counter == 0 && i > 1)
		return (0 && ft_printf("Error\n"));
	return (counter);
}

/*
*Checks if string contains numerous characters,
*and if so returns 1, otherway returns 0*/
static int	is_there_num(char *str)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-' \
			&& (str[i + 1] >= '0' && str[i + 1] <= '9')))
			check = 1;
		i++;
	}
	if (check == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

/*
*This function takes in the number of arguments and the argument array
*and splits the arguments into separate strings using whitespace as a delimiter.
*It returns a string array of the separated strings. The function also checks
*that all the strings in the arguments array are numbers and returns NULL
*if it finds a non-numeric string. If the function encounters any errors,
*it returns NULL and prints "Error" to the standard output.
*/
char	**spliter(int argv, char **argc)
{
	int		i;
	char	*all_there;
	char	**arr;
	char	*temp;

	i = 1;
	if (count_len(argv, argc) == 0)
		return (NULL);
	all_there = ft_strdup("");
	while (i < argv)
	{
		if (!is_there_num(argc[i]))
			return (free_str(all_there));
		temp = ft_strjoin(all_there, argc[i]);
		free(all_there);
		all_there = NULL;
		all_there = ft_strjoin(temp, " ");
		free(temp);
		i++;
	}
	arr = ft_split(all_there, ' ');
	if (arr == NULL)
		ft_printf("Error\n");
	free_str(all_there);
	return (arr);
}
