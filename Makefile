NAME		= libftprintf.a

PATH_LIBFT	= ./libft

LIBFT		= ./libft/libft.a

CC			= clang

CFLAGS		= -Wall -Werror -Wextra

SRC			=	ft_printf_wr.c\
				ft_printf_wr_hex.c\
				ft_printf.c\
				ft_printf_base.c\
				ft_uitoa.c\

OBJ			= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o:	%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -I $(PATH_LIBFT) -o $@

$(LIBFT):
	make -C $(PATH_LIBFT)

clean:
	rm -rf $(OBJ)
	make -C $(PATH_LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(PATH_LIBFT) fclean

re: fclean all

run:
	$(CC) $(FLAGS) ft_printf.c $(NAME) -I $(PATH_LIBFT) && ./a.out

sanitize:
	$(CC) $(CFLAGS) -fsanitize=address -g3 *.c $(NAME) && ./a.out

valgrind:
	$(CC) *.c
	valgrind ./a.out
