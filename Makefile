NAME			=	push_swap.a
CC			=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM			=	rm -rf
AR			=	ar rcs

LIBFT_P			=	libft
LIBFT			=	$(LIBFT_P)/libft.a
SRCS			=	push_swap.c checker.c stack_ops.c
OBJS			=	$(SRCS:.c=.o)

.DEFAULT_GOAL		=	all
HEADER			= 	push_swap.h

all:			$(NAME)

%.o:			%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(LIBFT) $(OBJS)
					cp $(LIBFT) $(NAME)
					$(AR) $(NAME) $?

$(LIBFT):
					make -C $(LIBFT_P) $?

clean:
					make -C $(LIBFT_P) clean
					$(RM) $(OBJS)

fclean:			clean
					make -C $(LIBFT_P) fclean
					$(RM) $(NAME)

re:				fclean all

.PHONY:	all clean fclean re libft

