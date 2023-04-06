NAME			=	push_swap
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf
AR				=	ar rcs

SRCD			=	srcs
OBJD			=	objs
SRCS			=	$(wildcard $(SRCD)/*.c)
OBJS			=	$(patsubst $(SRCD)/%.c,$(OBJD)/%.o,$(SRCS))

.DEFAULT_GOAL	=	all
HEADER			= 	./includes/push_swap.h

all:			$(NAME)

$(OBJD)/%.o:	$(SRCD)/%.c $(HEADER)
					-@mkdir -p $(OBJD)
					-@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS)
					-@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
					@echo "Build complete!"

clean:
					-@$(RM) $(OBJD)
					@echo "Cleaned!"

fclean:			clean
					-@$(RM) $(NAME)

re:				fclean all

.PHONY:	all clean fclean re libft