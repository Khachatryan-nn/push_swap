NAME			=	push_swap
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf
AR				=	ar rcs

SRCSDIR			=	srcs
OBJSDIR			=	objs
SRCS			=	$(wildcard $(SRCSDIR)/*.c)
OBJS			=	$(SRCS:.c=.o)

.DEFAULT_GOAL	=	all
HEADER			= 	./includes/push_swap.h

all:			$(NAME)

%.o:			%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
					$(RM) $(OBJS)

fclean:			clean
					$(RM) $(NAME)

re:				fclean all

.PHONY:	all clean fclean re libft