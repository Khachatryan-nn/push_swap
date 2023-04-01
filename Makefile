NAME			=	push_swap
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf
AR				=	ar rcs

LIBFT_P			=	./libft/srcs
LIBFT			=	$(LIBFT_P)/libft.a
FT_PRINTF_P		=	./libft/ft_printf
FT_PRINTF		=	$(FT_PRINTF_P)/libftprintf.a
GET_NEXT_LINE_P	=	./libft/get_next_line
GET_NEXT_LINE	=	$(GET_NEXT_LINE_P)/get_next_line.a

SRCS			=	push_swap.c checker.c stack_ops.c
OBJS			=	$(SRCS:.c=.o)

.DEFAULT_GOAL		=	all
HEADER			= 	push_swap.h

all:			$(NAME)

%.o:			%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(LIBFT) $(GET_NEXT_LINE) $(FT_PRINTF) $(OBJS)
					$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GET_NEXT_LINE) $(FT_PRINTF) -o $(NAME)
#					$(AR) $(NAME) $(OBJS)
#					cat $(LIBFT) $(GET_NEXT_LINE) $(FT_PRINTF) > $(NAME)

$(LIBFT):
					make -C $(LIBFT_P) $?
$(GET_NEXT_LINE):
					make -C $(GET_NEXT_LINE_P) $?
$(FT_PRINTF):
					make -C $(FT_PRINTF_P) $?

clean:
					make -C $(LIBFT_P) clean
					make -C $(FT_PRINTF_P) clean
					make -C $(GET_NEXT_LINE_P) clean
					$(RM) $(OBJS)

fclean:			clean
					make -C $(LIBFT_P) fclean
					make -C $(FT_PRINTF_P) fclean
					make -C $(GET_NEXT_LINE_P) fclean
					$(RM) $(NAME)

re:				fclean all

.PHONY:	all clean fclean re libft

