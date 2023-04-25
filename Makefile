NAME			=	push_swap
BONUS_NAME		=	checker
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf
AR				=	ar rcs

SRCD			=	srcs
OBJD			=	objs
SRCS			=	$(filter-out $(SRCD)/checker.c, $(wildcard $(SRCD)/*.c))
OBJS			=	$(patsubst $(SRCD)/%.c, $(OBJD)/%.o, $(filter-out $(SRCD)/checker.c, $(wildcard $(SRCD)/*.c)))
BONUS_SRCS		=	$(filter-out $(SRCD)/push_swap.c, wildcard $(SRCD)/*.c)
BONUS_OBJS		=	$(patsubst $(SRCD)/%.c, $(OBJD)/%.o, $(filter-out $(SRCD)/push_swap.c, $(wildcard $(SRCD)/*.c)))

.DEFAULT_GOAL	=	all
HEADER			= 	./includes/push_swap.h

all:			$(NAME)

$(OBJD)/%.o:	$(SRCD)/%.c $(HEADER)
					-@mkdir -p $(OBJD)
					-@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS)
					-@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
					@echo "Build complete!"

bonus:			$(BONUS_OBJS)
					-@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)
					@echo "Bonus build complete!"

clean:
					-@$(RM) $(OBJD)
					@echo "Cleaned."

fclean:			clean
					-@$(RM) $(NAME) $(BONUS_NAME)

re:				fclean all

.PHONY:	all clean fclean re bonus