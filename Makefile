NAME 		= libftprintf.a
CFLAGS 		= -Wall -Wextra -Werror -I.
CC = cc
SRCS = ft_printf.c \
	srcs/is_specifier.c  srcs/ft_initialise_tab.c srcs/ft_eval_format.c srcs/ft_specifier.c srcs/ft_print_char.c srcs/ft_print_str.c srcs/ft_print_adress.c  srcs/ft_print_unsigned.c \
	libft/ft_atoi.c libft/ft_sidigit.c libft/ft_isspace.c libft/ft_putstr.c  libft/ft_putchar.c libft/ft_putnbr.c libft/ft_puthex.c \
	flags/space_flag.c flags/plus_flag.c flags/shrap_flag.c \


OBJS	= $(SRCS:.c=.o)

bonus	:	all

all		:	$(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

clean  :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re    : fclean all bonus
