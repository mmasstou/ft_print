NAME 		= libftprintf.a
CFLAGS 		= -Wall -Wextra -Werror -I.
CC = cc
SRCS = ft_printf.c \
	srcs/is_specifier.c  srcs/ft_initialise_tab.c srcs/ft_eval_format.c srcs/ft_specifier.c srcs/ft_print_char.c srcs/ft_print_str.c srcs/ft_print_adress.c  srcs/ft_print_unsigned.c srcs/is_integer_specifier.c srcs/ft_resize_flags.c srcs/ft_putpercent.c srcs/update_index.c srcs/ft_nbrlen.c srcs/ft_hex_len.c \
	libft/ft_atoi.c libft/ft_sidigit.c libft/ft_isspace.c libft/ft_putstr.c  libft/ft_putchar.c libft/ft_putnbr.c libft/ft_puthex.c  libft/ft_strlen.c  libft/ft_substr.c libft/ft_strdup.c \
	flags/space_flag.c flags/plus_flag.c flags/shrap_flag.c flags/dash_flag.c flags/flags_check.c flags/point_flag.c flags/get_precision.c flags/zero_flag.c flags/ft_dash_pnt.c  flags/no_dash_pnt.c \
	specifier/string_specifier.c  specifier/x_specifier.c\
	
OBJS	= $(SRCS:.c=.o)

all		:	$(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus	: all

clean  :
	rm -f $(OBJS) $(BONUSOBJS)

fclean : clean
	rm -f $(NAME)

re    : fclean all bonus
