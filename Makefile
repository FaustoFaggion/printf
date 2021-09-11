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

SRC_BONUS	=	ft_printf_wr.c\
				ft_printf_wr_hex.c\
				ft_printf_bonus.c\
				ft_printf_base.c\
				ft_uitoa.c\

OBJ			= $(SRC:.c=.o)

OBJ_BONUS	= $(SRC_BONUS:.c=.o)

all:	$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o:	%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(PATH_LIBFT)

bonus: $(LIBFT) $(OBJ_BONUS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ_BONUS)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)
	make -C $(PATH_LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(PATH_LIBFT) fclean

re: fclean all

run:
	gcc $(FLAGS) main_printf.c $(NAME) && ./a.out

run_bonus:
	gcc $(FLAGS) main_printf_bonus.c $(NAME) && ./a.out

sanitize:
	gcc $(CFLAGS) -fsanitize=address -g3 *.c && ./a.out

valgrind:
	gcc *.c
	valgrind ./a.out
