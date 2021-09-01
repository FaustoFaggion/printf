NAME		:= libftprintf.a

CC			:= clang

CFLAGS		:= -Wall -Werror -Wextra

SRC			:= 	ft_itoa.c/
				ft_printf_writes.c/
				ft_printf.c/
				ft_putnbr_base.c/
				ft_strdup.c/
				ft_strlen.c/
				ft_unsigned_itoa.c/

SRC_BONUS	:=

OBJ			:= $(SRC:.c=.o)

OBJ_BONUS	:= $(SRC_BONUS:.c=.o)

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
	gcc -Wall -Wextra -Werror -fsanitize=address -g3 get_next_line.c get_next_line_utils.c main.c && ./a.out

valgrind:
	gcc get_next_line.c get_next_line_utils.c main.c
	valgrind ./a.out
