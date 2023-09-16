NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC =  ft_printf.c \
		s.c \
		c.c \
		d.c \
		u.c \
		x.c \
		p.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c 
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@make -s -C ../Libft/
	@cp ../Libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJ)

clean:
	@make -s clean -C ../Libft/
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:		fclean all