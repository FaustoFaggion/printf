NAME		:= libftprintf.a

CC			:= clang

CFLAGS		:= -Wall -Werror -Wextra

SRC			:=	ft_itoa.c\
                ft_printf_wr.c\
				ft_printf_wr_hex.c\
                ft_printf.c\
                ft_printf_base.c\
                ft_strdup.c\
                ft_strlen.c\
                ft_unsigned_itoa.c

OBJ			:= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o:	%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

bonus: $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run:
	gcc -Wall -Wextra -Werror -fsanitize=address -g3 *.c && ./a.out

valgrind:
	gcc *.c
	valgrind ./a.out
