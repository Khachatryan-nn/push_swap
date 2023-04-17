/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:50:23 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/17 16:17:27 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <fcntl.h>
# include <limits.h>

/*
*	int				d;
*	unsigned int	index;
*	struct s_list	*p;
*	struct s_list	*n;*/
typedef struct s_list
{
	int				d;
	int				index;
	struct s_list	*p;
	struct s_list	*n;
}					t_list;

void	rev_quick_sort_part_2(t_list **a, t_list **b, int *i, int j);
void	rev_quick_sort_part_1(t_list **a, t_list **b, int *i, int *j);
void	rev_quick_sort_part_3(t_list **a, t_list **b, int j, int *c);
void	quick_sort_part_1(t_list **a, t_list **b, int mid, int *i);
void	rev_quick_sort_part_4(t_list **a, t_list **b, int j);
void	push_and_increment(t_list **a, t_list **b, int *i);
void	push_swap_utils_4(t_list **a, t_list **b, int *n);
void	quick_sort(t_list **a, t_list **b, int n, int c);
void	sorting_for_large(t_list **a, t_list **b, int n);
int		rev_quick_sort(t_list **a, t_list **b, int n);
int		free_all(t_list *a, t_list *b, int	*int_arr);
t_list	*fill_a(int argv, char **argc, int *len);
void	sorting(t_list **a, t_list **b, int n);
int		*fill_int_arr(t_list *start, int len);
void	sort_array_buttefly(int *x, int len);
void	indexing(t_list *a, int *x, int len);
void	rrotate_both(t_list **a, t_list **b);
void	rotate_both(t_list **a, t_list **b);
void	push(t_list **a, t_list **b, int n);
int		free_stacks(t_list *a, t_list *b);
void	reverse_sort_3(t_list **a, int n);
void	swap_both(t_list **a, t_list **b);
char	**spliter(int argN, char **args);
void	sort_3intop(t_list **a, int n);
void	print_int_array(int *x, int n);
void	rrotate(t_list **nodes, int n);
void	rotate(t_list **nodes, int n);
void	sort_int_arr(int *x, int len);
int		otrs(t_list *start, int mid);
void	swap(t_list **start, int n);
int		mor(t_list *start, int len);
void	print_list(t_list *start);
void	sort_3(t_list **a, int n);
int		tnilt(t_list *a, int k);
void	rsrr(t_list **a, int n);
char	**free_str(char	*str);
char	**free_str(char	*str);
int		free_a(t_list *a);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_isdigit(char c);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int d);
char	*get_next_line(int fd);
int		ft_percentage(char type, va_list arg);
int		ft_putnbrhex(unsigned int nb, char c);
char	*ft_itoahex(unsigned int n, char c);
int		ft_printf(const char *arg, ...);
int		ft_putptrhex(char const *ptr);
int		ft_putnbrun(unsigned int nb);
char	*ft_itoaptrhex(uintptr_t n);
char	*ft_itoaun(unsigned int n);
char	*ft_itoaun(unsigned int n);
int		ft_putstr(char *s, int t);
int		ft_putchr(char c);
int		ft_putnbr(int nb);

#endif
