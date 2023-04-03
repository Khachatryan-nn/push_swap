#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
# include "libft/includes/get_next_line_bonus.h"

int		check_err(int argN, char **args);
t_list	*fill_a(char **args, int len);
void	swap(t_list **start);
void	pushb(t_list **a, t_list **b);
void	print_list(t_list *start);

#endif
