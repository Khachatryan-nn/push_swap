NAME			=	get_next_line.a
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf
AR				=	ar rcs
SRCS			=	get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS			=	$(SRCS:.c=.o)

.DEGAULT_GOAL	=	all
HEADER			=	get_next_line.h

all:			$(NAME)

%.o:			%.c $(HEADER)
					-@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS)
					-@ $(AR) $(NAME) $?

clean:
			-@ $(RM) $(OBJS)

fclean:		clean
			-@ $(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re

