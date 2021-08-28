NAME		:= libftprintf.a

CC			:= clang

CFLAGS		:= -Wall -Werror -Wextra

SRC			:= 	ft_printf.c/

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
